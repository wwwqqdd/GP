#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"

class FConversationBranchOptionCustomization : public IPropertyTypeCustomization
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
    void OnTargetNodeChanged(TSharedPtr<FString> NewValue, ESelectInfo::Type SelectInfo);
    FText GetCurrentTargetNodeText() const;

    TSharedPtr<IPropertyHandle> TargetNodeHandle;
    TArray<TSharedPtr<FString>> RowNameOptions;
};
