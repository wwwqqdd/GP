// Fill out your copyright notice in the Description page of Project Settings.

#include "Misc/AutomationTest.h"
#include "Interaction/InteractionScoring.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FInteractionScoringTest,
    "GameplayProject.Interaction.Scoring",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FInteractionScoringTest::RunTest(const FString& Parameters)
{
    using namespace InteractionScoring;

    const FVector Origin(0, 0, 0);
    const FVector Forward(1, 0, 0);
    const float Radius = 250.f;

    // 1) 更近的候选得分更高（不过滤朝向）
    const float Near = ScoreCandidate(Origin, Forward, FVector(50, 0, 0), Radius, 0.f);
    const float Far  = ScoreCandidate(Origin, Forward, FVector(200, 0, 0), Radius, 0.f);
    TestTrue(TEXT("近的候选评分高于远的"), Near > Far);

    // 2) 同距离下，正对前方的得分高于侧方
    const float Front = ScoreCandidate(Origin, Forward, FVector(100, 0, 0), Radius, 0.f);
    const float Side  = ScoreCandidate(Origin, Forward, FVector(0, 100, 0), Radius, 0.f);
    TestTrue(TEXT("正前方评分高于侧方"), Front > Side);

    // 3) 朝向阈值剔除：背后候选在 threshold=0.3 下被剔除（返回负）
    const float Behind = ScoreCandidate(Origin, Forward, FVector(-100, 0, 0), Radius, 0.3f);
    TestTrue(TEXT("阈值下背后候选被剔除"), Behind < 0.f);

    // 4) 评分始终在合理上界内（非剔除时 <= 1）
    TestTrue(TEXT("正常评分不超过1"), Front <= 1.0f + KINDA_SMALL_NUMBER);

    return true;
}
