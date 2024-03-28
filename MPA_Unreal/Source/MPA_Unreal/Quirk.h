// Quirk.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Quirk.generated.h"


UCLASS(Blueprintable, BlueprintType)
class MPA_UNREAL_API UQuirk : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Quirk")
    FString Name;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Quirk")
    FString Category;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Quirk")
    FString Section;

    UQuirk();

};