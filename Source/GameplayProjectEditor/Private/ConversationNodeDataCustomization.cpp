#include "ConversationNodeDataCustomization.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "Widgets/Input/SComboBox.h"
#include "Conversation/ConversationDefinition.h"
#include "Conversation/ConversationSettings.h"

TSharedRef<IPropertyTypeCustomization> FConversationNodeDataCustomization::MakeInstance()
{
    return MakeShareable(new FConversationNodeDataCustomization());
}

void FConversationNodeDataCustomization::CustomizeHeader(
    TSharedRef<IPropertyHandle> StructPropertyHandle,
    FDetailWidgetRow& HeaderRow,
    IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
    HeaderRow.NameContent()
    [
        StructPropertyHandle->CreatePropertyNameWidget()
    ];
}

void FConversationNodeDataCustomization::CustomizeChildren(
    TSharedRef<IPropertyHandle> StructPropertyHandle,
    IDetailChildrenBuilder& StructBuilder,
    IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
    uint32 NumChildren = 0;
    StructPropertyHandle->GetNumChildren(NumChildren);

    DefaultNextNodeHandle = StructPropertyHandle->GetChildHandle(
        GET_MEMBER_NAME_CHECKED(FConversationNodeData, DefaultNextNodeRowName));

    RebuildRowNameOptions();

    for (uint32 i = 0; i < NumChildren; ++i)
    {
        TSharedRef<IPropertyHandle> ChildHandle = StructPropertyHandle->GetChildHandle(i).ToSharedRef();

        if (ChildHandle->GetProperty()->GetFName() == GET_MEMBER_NAME_CHECKED(FConversationNodeData, DefaultNextNodeRowName))
        {
            StructBuilder.AddCustomRow(FText::FromString(TEXT("DefaultNextNodeRowName")))
                .NameContent()
                [
                    ChildHandle->CreatePropertyNameWidget()
                ]
                .ValueContent()
                .MinDesiredWidth(200.0f)
                [
                    SNew(SComboBox<TSharedPtr<FString>>)
                    .OptionsSource(&RowNameOptions)
                    .OnGenerateWidget_Lambda([](TSharedPtr<FString> Item)
                    {
                        return SNew(STextBlock).Text(FText::FromString(*Item));
                    })
                    .OnSelectionChanged(this, &FConversationNodeDataCustomization::OnDefaultNextNodeChanged)
                    [
                        SNew(STextBlock).Text(this, &FConversationNodeDataCustomization::GetCurrentDefaultNextNodeText)
                    ]
                ];
        }
        else
        {
            StructBuilder.AddProperty(ChildHandle);
        }
    }
}

void FConversationNodeDataCustomization::RebuildRowNameOptions()
{
    RowNameOptions.Empty();
    RowNameOptions.Add(MakeShareable(new FString(TEXT("None"))));

    UConversationSettings* Settings = GetMutableDefault<UConversationSettings>();
    if (!Settings) return;

    UDataTable* DT = Settings->GetConversationDataTable();
    if (!DT) return;

    TArray<FName> RowNames = DT->GetRowNames();
    for (const FName& Name : RowNames)
    {
        RowNameOptions.Add(MakeShareable(new FString(Name.ToString())));
    }
}

void FConversationNodeDataCustomization::OnDefaultNextNodeChanged(
    TSharedPtr<FString> NewValue, ESelectInfo::Type SelectInfo)
{
    if (!DefaultNextNodeHandle.IsValid() || !NewValue.IsValid()) return;

    if (*NewValue == TEXT("None"))
    {
        DefaultNextNodeHandle->SetValue(FName(NAME_None));
    }
    else
    {
        DefaultNextNodeHandle->SetValue(FName(**NewValue));
    }
}

FText FConversationNodeDataCustomization::GetCurrentDefaultNextNodeText() const
{
    if (!DefaultNextNodeHandle.IsValid()) return FText::FromString(TEXT("None"));

    FName CurrentValue;
    DefaultNextNodeHandle->GetValue(CurrentValue);

    if (CurrentValue.IsNone())
    {
        return FText::FromString(TEXT("None"));
    }
    return FText::FromName(CurrentValue);
}
