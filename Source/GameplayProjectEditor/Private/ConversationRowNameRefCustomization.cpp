#include "ConversationRowNameRefCustomization.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "Widgets/Input/SComboBox.h"
#include "Conversation/ConversationDefinition.h"
#include "Conversation/ConversationSettings.h"

TSharedRef<IPropertyTypeCustomization> FConversationRowNameRefCustomization::MakeInstance()
{
    return MakeShareable(new FConversationRowNameRefCustomization());
}

void FConversationRowNameRefCustomization::CustomizeHeader(
    TSharedRef<IPropertyHandle> StructPropertyHandle,
    FDetailWidgetRow& HeaderRow,
    IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
    RowNameHandle = StructPropertyHandle->GetChildHandle(
        GET_MEMBER_NAME_CHECKED(FConversationRowNameRef, RowName));

    RebuildRowNameOptions();

    HeaderRow.NameContent()
    [
        StructPropertyHandle->CreatePropertyNameWidget()
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
        .OnSelectionChanged(this, &FConversationRowNameRefCustomization::OnRowNameChanged)
        [
            SNew(STextBlock).Text(this, &FConversationRowNameRefCustomization::GetCurrentRowNameText)
        ]
    ];
}

void FConversationRowNameRefCustomization::CustomizeChildren(
    TSharedRef<IPropertyHandle> StructPropertyHandle,
    IDetailChildrenBuilder& StructBuilder,
    IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
    // 不展开子属性 — 下拉框已在 Header 中完整显示
}

void FConversationRowNameRefCustomization::RebuildRowNameOptions()
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

void FConversationRowNameRefCustomization::OnRowNameChanged(
    TSharedPtr<FString> NewValue, ESelectInfo::Type SelectInfo)
{
    if (!RowNameHandle.IsValid() || !NewValue.IsValid()) return;

    if (*NewValue == TEXT("None"))
    {
        RowNameHandle->SetValue(FName(NAME_None));
    }
    else
    {
        RowNameHandle->SetValue(FName(**NewValue));
    }
}

FText FConversationRowNameRefCustomization::GetCurrentRowNameText() const
{
    if (!RowNameHandle.IsValid()) return FText::FromString(TEXT("None"));

    FName CurrentValue;
    RowNameHandle->GetValue(CurrentValue);

    if (CurrentValue.IsNone())
    {
        return FText::FromString(TEXT("None"));
    }
    return FText::FromName(CurrentValue);
}
