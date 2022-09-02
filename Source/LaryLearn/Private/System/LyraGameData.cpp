// Fill out your copyright notice in the Description page of Project Settings.


#include "System/LyraGameData.h"
#include "System/LyraAssetManager.h"

ULyraGameData::ULyraGameData()
{
}

const ULyraGameData& ULyraGameData::ULyraGameData::Get()
{
	return ULyraAssetManager::Get().GetGameData();
}