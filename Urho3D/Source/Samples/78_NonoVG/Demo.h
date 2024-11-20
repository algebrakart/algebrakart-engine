#pragma once

#include "VGElement.h"
#include "VGFrameBuffer.h"

using namespace Urho3D;

struct DemoData
{
    int fontNormal, fontBold, fontIcons, fontEmoji;
    int images[12];
    int svgImage;
};
typedef struct DemoData DemoData;


void loadDemoData(NanoVG* vge, DemoData* data);

void renderVGElement(VGElement * vgElement, float mx, float my, float width, float height, float t, int blowup, DemoData* data);
