#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"

class FConversationNodeDataCustomization : public IPropertyTypeCustomization
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
    void OnDefaultNextNodeChanged(TSharedPtr<FString> NewValue, ESelectInfo::Type SelectInfo);
    FText GetCurrentDefaultNextNodeText() const;

    TSharedPtr<IPropertyHandle> DefaultNextNodeHandle;
    TArray<TSharedPtr<FString>> RowNameOptions;
};
