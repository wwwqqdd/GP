#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"

class FConversationRowNameRefCustomization : public IPropertyTypeCustomization
{
public:
    static TSharedRef<IPropertyTypeCustomization> MakeInstance();

    virtual void CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle,
        FDetailWidgetRow& HeaderRow,
        IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;

    virtual void CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle,
        IDetailChildrenBuilder& StructBuilder,
        IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;

private:
    void RebuildRowNameOptions();
    void OnRowNameChanged(TSharedPtr<FString> NewValue, ESelectInfo::Type SelectInfo);
    FText GetCurrentRowNameText() const;

    TSharedPtr<IPropertyHandle> RowNameHandle;
    TArray<TSharedPtr<FString>> RowNameOptions;
};
