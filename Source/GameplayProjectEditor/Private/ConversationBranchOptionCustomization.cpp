#include "ConversationBranchOptionCustomization.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "Widgets/Input/SComboBox.h"
#include "Conversation/ConversationDefinition.h"
#include "Conversation/ConversationSettings.h"

TSharedRef<IPropertyTypeCustomization> FConversationBranchOptionCustomization::MakeInstance()
{
    return MakeShareable(new FConversationBranchOptionCustomization());
}

void FConversationBranchOptionCustomization::CustomizeHeader(
    TSharedRef<IPropertyHandle> StructPropertyHandle,
    FDetailWidgetRow& HeaderRow,
    IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
    HeaderRow.NameContent()
    [
        StructPropertyHandle->CreatePropertyNameWidget()
    ];
}

void FConversationBranchOptionCustomization::CustomizeChildren(
    TSharedRef<IPropertyHandle> StructPropertyHandle,
    IDetailChildrenBuilder& StructBuilder,
    IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
    uint32 NumChildren = 0;
    StructPropertyHandle->GetNumChildren(NumChildren);

    TargetNodeHandle = StructPropertyHandle->GetChildHandle(
        GET_MEMBER_NAME_CHECKED(FConversationBranchOption, TargetNodeRowName));

    RebuildRowNameOptions();

    for (uint32 i = 0; i < NumChildren; ++i)
    {
        TSharedRef<IPropertyHandle> ChildHandle = StructPropertyHandle->GetChildHandle(i).ToSharedRef();

        if (ChildHandle->GetProperty()->GetFName() == GET_MEMBER_NAME_CHECKED(FConversationBranchOption, TargetNodeRowName))
        {
            StructBuilder.AddCustomRow(FText::FromString(TEXT("TargetNodeRowName")))
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
                    .OnSelectionChanged(this, &FConversationBranchOptionCustomization::OnTargetNodeChanged)
                    [
                        SNew(STextBlock).Text(this, &FConversationBranchOptionCustomization::GetCurrentTargetNodeText)
                    ]
                ];
        }
        else
        {
            StructBuilder.AddProperty(ChildHandle);
        }
    }
}

void FConversationBranchOptionCustomization::RebuildRowNameOptions()
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

void FConversationBranchOptionCustomization::OnTargetNodeChanged(
    TSharedPtr<FString> NewValue, ESelectInfo::Type SelectInfo)
{
    if (!TargetNodeHandle.IsValid() || !NewValue.IsValid()) return;

    if (*NewValue == TEXT("None"))
    {
        TargetNodeHandle->SetValue(FName(NAME_None));
    }
    else
    {
        TargetNodeHandle->SetValue(FName(**NewValue));
    }
}

FText FConversationBranchOptionCustomization::GetCurrentTargetNodeText() const
{
    if (!TargetNodeHandle.IsValid()) return FText::FromString(TEXT("None"));

    FName CurrentValue;
    TargetNodeHandle->GetValue(CurrentValue);

    if (CurrentValue.IsNone())
    {
        return FText::FromString(TEXT("None"));
    }
    return FText::FromName(CurrentValue);
}
