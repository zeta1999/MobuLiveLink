﻿// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once
#include <string>
#include "MobuLiveLinkDevice.h"


class MobuLiveLinkLayout : public FBDeviceLayout
{
	FBDeviceLayoutDeclare(MobuLiveLinkLayout, FBDeviceLayout);

public:
	virtual bool FBCreate();
	virtual void FBDestroy();

	// UI Management
	void UICreate();
	void UIConfigure();
	void UIReset();
	void UIRefresh();

	// Main Layout: Events
	void EventDeviceStatusChange(HISender Sender, HKEvent Event);
	void EventUIIdle(HISender Sender, HKEvent Event);
	void EventAddToStream(HISender Sender, HKEvent Event);

public:

	FBLayout					StreamLayout;

	FBPropertyConnectionEditor	ObjectSelector;
	FBButton					AddToStreamButton;
	FBButton					RemoveFromStreamButton;
	FBSpread					StreamSpread;

private:

	typedef void (MobuLiveLinkLayout::*ModelStoreFunctionType)(FBModel* CameraModel);

	void StoreCamera(FBModel* CameraModel);

	TMap<int, ModelStoreFunctionType> ModelStoreFunctions;

	FBSystem				System;
	MobuLiveLink*			LiveLinkDevice;

	FBPropertyListObject ObjectSelection;
};