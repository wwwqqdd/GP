#include "GameplayProjectEditor.h"
#include "PropertyEditorModule.h"
#include "ConversationNodeDataCustomization.h"
#include "ConversationBranchOptionCustomization.h"

#define LOCTEXT_NAMESPACE "FGameplayProjectEditorModule"

void FGameplayProjectEditorModule::StartupModule()
{
    FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

    PropertyModule.RegisterCustomPropertyTypeLayout(
        "ConversationNodeData",
        FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FConversationNodeDataCustomization::MakeInstance));

    PropertyModule.RegisterCustomPropertyTypeLayout(
        "ConversationBranchOption",
        FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FConversationBranchOptionCustomization::MakeInstance));

    PropertyModule.NotifyCustomizationModuleChanged();
}

void FGameplayProjectEditorModule::ShutdownModule()
{
    if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
    {
        FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
        PropertyModule.UnregisterCustomPropertyTypeLayout("ConversationNodeData");
        PropertyModule.UnregisterCustomPropertyTypeLayout("ConversationBranchOption");
    }
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGameplayProjectEditorModule, GameplayProjectEditor)
