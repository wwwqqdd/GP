// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

namespace InteractionScoring
{
    /**
     * 给一个候选交互物打分。分越高越优先。
     * @param InstigatorLocation 交互者位置
     * @param InstigatorForward  交互者前向（应为单位向量）
     * @param CandidateLocation  候选物位置
     * @param DetectionRadius    检测半径（cm），用于归一化距离
     * @param FacingDotThreshold 朝向点积阈值；为 0 表示不过滤；>0 时 Dot 低于它的候选返回 -1
     * @return [0,1] 的评分；被剔除返回 -1
     */
    inline float ScoreCandidate(
        const FVector& InstigatorLocation,
        const FVector& InstigatorForward,
        const FVector& CandidateLocation,
        float DetectionRadius,
        float FacingDotThreshold)
    {
        const FVector ToCandidate = CandidateLocation - InstigatorLocation;
        const float Dist = ToCandidate.Size();

        // 朝向点积（候选与正前方夹角）
        const FVector Dir = Dist > KINDA_SMALL_NUMBER ? (ToCandidate / Dist) : InstigatorForward;
        const float Dot = FVector::DotProduct(InstigatorForward.GetSafeNormal(), Dir);

        if (FacingDotThreshold != 0.f && Dot < FacingDotThreshold)
        {
            return -1.f; // 朝向不满足，剔除
        }

        const float SafeRadius = FMath::Max(DetectionRadius, KINDA_SMALL_NUMBER);
        const float DistScore = FMath::Clamp(1.f - Dist / SafeRadius, 0.f, 1.f);
        const float FacingScore = (Dot + 1.f) * 0.5f; // [-1,1] → [0,1]

        return 0.7f * DistScore + 0.3f * FacingScore;
    }
}
