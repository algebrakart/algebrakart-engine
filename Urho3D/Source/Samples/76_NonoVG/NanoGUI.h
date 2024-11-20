/*!
 * \file NanoGUI.h
 *
 * \author vitali
 * \date Februar 2015
 *
 * 
 */

#pragma once
#include <Urho3D/Core/Object.h>

#pragma once
#if defined(URHO3D_ANGLE_METAL)
#if URHO3D_GLES3
#include <angle/GLES2/gl2ext.h>
#include <angle/GLES3/gl3.h>
#else
#include <angle/GLES2/gl2.h>
#include <angle/GLES2/gl2ext.h>
#endif
#elif defined(IOS) || defined(TVOS)
#if URHO3D_GLES3
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>
#else
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#ifndef URHO3D_GLES2
#define URHO3D_GLES2
#endif
#endif
#elif defined(__ANDROID__) || defined(__arm__) || (defined(__aarch64__) && !defined(APPLE_SILICON)) ||                 \
    defined(__EMSCRIPTEN__)
#if URHO3D_GLES3
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>
#else
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#ifndef URHO3D_GLES2
#define URHO3D_GLES2
#endif
#endif
#else
#include <GLEW/glew.h>
#endif

struct NVGcontext;
struct NVGLUframebuffer;


namespace Urho3D
{
	class Graphics;
	class VertexBuffer;
	class Cursor;
	class ResourceCache;
	class Timer;
	class UIBatch;
	class UIElement;
	class XMLElement;
	class XMLFile;

	struct Theme {
	public:
		/* Fonts */
		int mFontNormal;
		int mFontBold;
		int mFontIcons;

		/* Spacing-related parameters */
		int mStandardFontSize;
		int mButtonFontSize;
		int mWindowCornerRadius;
		int mWindowHeaderHeight;
		int mWindowDropShadowSize;
		int mButtonCornerRadius;

		/* Generic colors */
		Color mDropShadow;
		Color mTransparent;
		Color mBorderDark;
		Color mBorderLight;
		Color mBorderMedium;
		Color mTextColor;
		Color mDisabledTextColor;
		Color mTextColorShadow;
		Color mIconColor;

		/* Button colors */
		Color mButtonGradientTopFocused;
		Color mButtonGradientBotFocused;
		Color mButtonGradientTopUnfocused;
		Color mButtonGradientBotUnfocused;
		Color mButtonGradientTopPushed;
		Color mButtonGradientBotPushed;

		/* Window colors */
		Color mWindowFillUnfocused;
		Color mWindowFillFocused;
		Color mWindowTitleUnfocused;
		Color mWindowTitleFocused;

		Color mWindowHeaderGradientTop;
		Color mWindowHeaderGradientBot;
		Color mWindowHeaderSepTop;
		Color mWindowHeaderSepBot;

		Color mWindowPopup;
		Color mWindowPopupTransparent;

		Theme(NVGcontext *ctx);
	};

class NanoGUI : public Object
{
    URHO3D_OBJECT(NanoGUI, Object);

public:
	NanoGUI(Context* context);
	virtual ~NanoGUI();
	static void RegisterObject(Context* context);
	/// Initialize when screen mode initially set.
	void Initialize();
	/// Clear the UI (excluding the cursor.)
	void Clear();
	/// Update the UI logic. Called by HandlePostUpdate().
	void Update(float timeStep);
	/// Render the UI. If resetRenderTargets is true, is assumed to be the default UI render to backbuffer called by Engine, and will be performed only once. Additional UI renders to a different rendertarget may be triggered from the renderpath.
	void Render(bool resetRenderTargets = true);


protected:
	/// Handle logic post-update event.
	void HandlePostUpdate(StringHash eventType, VariantMap& eventData);
	/// Handle render event.
	void HandleRender(StringHash eventType, VariantMap& eventData);
	/// Initialized flag.
	bool initialized_;
	/// Graphics subsystem.
	WeakPtr<Graphics> graphics_;

	/// nanovg context
	NVGcontext* vg_;

	float time_;

private:
};
}

