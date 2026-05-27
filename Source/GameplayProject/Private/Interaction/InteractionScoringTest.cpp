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
    // 剔除返回值精确为负
    TestTrue(TEXT("被剔除候选返回值严格 < 0"), Behind < 0.f);

    // 4) 评分始终在合理上界内（非剔除时 <= 1）
    TestTrue(TEXT("正常评分不超过1"), Front <= 1.0f + KINDA_SMALL_NUMBER);

    // 5) 非剔除评分下界：正常评分 >= 0
    TestTrue(TEXT("正常评分不低于0"), Front >= 0.f);
    TestTrue(TEXT("侧方评分不低于0"), Side >= 0.f);

    // 6) 除零兜底：DetectionRadius = 0 时不崩、返回有限值
    const float ZeroRadius = ScoreCandidate(Origin, Forward, FVector(100, 0, 0), 0.f, 0.f);
    TestTrue(TEXT("半径为0时返回有限值"), FMath::IsFinite(ZeroRadius));
    TestTrue(TEXT("半径为0时评分在 [0,1]"), ZeroRadius >= 0.f && ZeroRadius <= 1.0f + KINDA_SMALL_NUMBER);

    // 7) 零距离：候选与交互者同位置（ToCandidate 为零向量）回退 InstigatorForward
    //    返回有限值且不被剔除（threshold=0）
    const float ZeroDist = ScoreCandidate(Origin, Forward, Origin, Radius, 0.f);
    TestTrue(TEXT("零距离返回有限值"), FMath::IsFinite(ZeroDist));
    TestTrue(TEXT("零距离不被剔除（threshold=0）"), ZeroDist >= 0.f);

    // 8) 边界：Dot 恰好等于阈值时不剔除（条件为 Dot < threshold 才剔除）
    //    令候选正前方 → Dot=1；阈值取 1 → Dot==threshold，应保留（返回 >= 0）
    const float DotEqualsThreshold = ScoreCandidate(Origin, Forward, FVector(100, 0, 0), Radius, 1.0f);
    TestTrue(TEXT("Dot 恰好等于阈值时不剔除"), DotEqualsThreshold >= 0.f);

    return true;
}
