#pragma once

#include "imgui_internal.h"

namespace Chicane
{
    void constrainWindowTranslation(
        ImVec2& outTargetPosition,
        ImGuiWindow* inWindow,
        const ImVec2& inOffset
    );
    void constraintWindowResizing(ImVec2& outNextSize, ImGuiWindow* inWindow);
}