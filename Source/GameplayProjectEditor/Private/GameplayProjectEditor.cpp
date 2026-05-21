#include "GameplayProjectEditor.h"
#include "PropertyEditorModule.h"
#include "ConversationRowNameRefCustomization.h"

#define LOCTEXT_NAMESPACE "FGameplayProjectEditorModule"

void FGameplayProjectEditorModule::StartupModule()
{
    FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

    PropertyModule.RegisterCustomPropertyTypeLayout(
        "ConversationRowNameRef",
        FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FConversationRowNameRefCustomization::MakeInstance));

    PropertyModule.NotifyCustomizationModuleChanged();
}

void FGameplayProjectEditorModule::ShutdownModule()
{
    if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
    {
        FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
        PropertyModule.UnregisterCustomPropertyTypeLayout("ConversationRowNameRef");
    }
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGameplayProjectEditorModule, GameplayProjectEditor)
