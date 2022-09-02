// Copyright Epic Games, Inc. All Rights Reserved.

#include "System/LyraAssetManagerStartupJob.h"

#include "Kismet/KismetSystemLibrary.h"

TSharedPtr<FStreamableHandle> FLyraAssetManagerStartupJob::DoJob() const
{
	const double JobStartTime = FPlatformTime::Seconds();

	TSharedPtr<FStreamableHandle> Handle;
	
	UKismetSystemLibrary::PrintString(nullptr,FString::Printf(TEXT("Startup job \"%s\" starting"), *JobName));

	JobFunc(*this, Handle);

	if (Handle.IsValid())
	{
		Handle->BindUpdateDelegate(FStreamableUpdateDelegate::CreateRaw(this, &FLyraAssetManagerStartupJob::UpdateSubstepProgressFromStreamable));
		Handle->WaitUntilComplete(0.0f, false);
		Handle->BindUpdateDelegate(FStreamableUpdateDelegate());
	}
	
	UKismetSystemLibrary::PrintString(nullptr,FString::Printf(TEXT("Startup job \"%s\" took %.2f seconds to complete"), *JobName, FPlatformTime::Seconds() - JobStartTime));

	return Handle;
}
