#include "imgui_chicane.h"

namespace Chicane
{
    void constrainWindowTranslation(
        ImVec2& outNextPosition,
        ImGuiWindow* inWindow,
        const ImVec2& inOffset
    )
    {
        if (!inWindow->IsConstrained || inWindow->Viewport == NULL)
        {
            return;
        }

        ImRect constraint = inWindow->Viewport->GetWorkRect();

        ImVec2 nextPosition = outNextPosition;
        nextPosition.x     += inOffset.x;
        nextPosition.y     += inOffset.y;

        if (nextPosition.x < constraint.Min.x || nextPosition.x > constraint.Max.x)
        {
            outNextPosition.x = inWindow->Pos.x;
        }

        if (nextPosition.y < constraint.Min.y || nextPosition.y > constraint.Max.y)
        {
            outNextPosition.y = inWindow->Pos.y;
        }
    }

    void constraintWindowResizing(ImVec2& outNextSize, ImGuiWindow* inWindow)
    {
        if (!inWindow->IsConstrained || inWindow->Viewport == NULL)
        {
            return;
        }

        ImVec2 windowSize = inWindow->SizeFull;

        ImRect constraintRect = inWindow->Viewport->GetWorkRect();
        ImRect targetRect     = inWindow->Rect();

        ImVec2 expansion(0.0f, 0.0f);

        float xDiff = outNextSize.x - windowSize.x;
        expansion.x = xDiff;
        targetRect.Expand(expansion);

        if (!constraintRect.Contains(targetRect))
        {
            outNextSize.x = windowSize.x;

            expansion.x = -xDiff;
            targetRect.Expand(expansion);
        }

        expansion.x = 0.0f;

        float yDiff = outNextSize.y - windowSize.y;
        expansion.y = yDiff;
        targetRect.Expand(expansion);

        if (!constraintRect.Contains(targetRect))
        {
            outNextSize.y = windowSize.y;
        }
    }
}