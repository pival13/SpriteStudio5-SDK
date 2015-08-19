#include "../wtafx.h"
#include "wtUIPanel.h"
#include "wtUIMainFrame.h"	



void	wtUIPanel::resize( int x , int y , int w , int h )
{
	position.x = x;
	position.y = y;
	width = w;
	height = h;
	this->onResize( w , h);
}

void	wtUIPanel::update()
{
//	wtUIMainFrame* mf = static_cast<wtUIMainFrame*>(this->get_root());

	drawPosition = position;
	drawWidth = width;
	drawHeight = height;
/*	
	//dock calculate
	//たぶん本当はMainframeのpreupdateで終わらせておく
	if ( DockStatus == wtUI::Dock::left )
	{
		drawPosition.x = 0;
		drawPosition.y = 0;
		drawHeight = 0;
	}
*/
}


void	wtUIPanel::draw()
{

	float x = drawPosition.x;
	float y = drawPosition.y;

	float w = drawWidth;
	float h = drawHeight;
	

	const char* title = caption.c_str();

	float cornerRadius = 3.0f;
	NVGpaint shadowPaint;
	NVGpaint headerPaint;

	nvgSave(vg);
//	nvgClearState(vg);

	// Window
	nvgBeginPath(vg);
	nvgRoundedRect(vg, x,y, w,h, cornerRadius);
	nvgFillColor(vg, nvgRGBA(28,30,34,192));
//	nvgFillColor(vg, nvgRGBA(0,0,0,128));
	nvgFill(vg);

	// Drop shadow
	shadowPaint = nvgBoxGradient(vg, x,y+2, w,h, cornerRadius*2, 10, nvgRGBA(0,0,0,128), nvgRGBA(0,0,0,0));
	nvgBeginPath(vg);
	nvgRect(vg, x-10,y-10, w+20,h+30);
	nvgRoundedRect(vg, x,y, w,h, cornerRadius);
	nvgPathWinding(vg, NVG_HOLE);
	nvgFillPaint(vg, shadowPaint);
	nvgFill(vg);

	// Header
	headerPaint = nvgLinearGradient(vg, x,y,x,y+15, nvgRGBA(255,255,255,8), nvgRGBA(0,0,0,16));
	nvgBeginPath(vg);
	nvgRoundedRect(vg, x+1,y+1, w-2,30, cornerRadius-1);
	nvgFillPaint(vg, headerPaint);
	nvgFill(vg);
	nvgBeginPath(vg);
	nvgMoveTo(vg, x+0.5f, y+0.5f+30);
	nvgLineTo(vg, x+0.5f+w-1, y+0.5f+30);
	nvgStrokeColor(vg, nvgRGBA(0,0,0,32));
	nvgStroke(vg);


	nvgBeginPath(vg);
	nvgFontSize(vg, 18.0f);
	nvgFontFace(vg, "japanease");
	nvgTextAlign(vg,NVG_ALIGN_CENTER|NVG_ALIGN_MIDDLE);

	nvgFontBlur(vg,2);
	nvgFillColor(vg, nvgRGBA(0,0,0,128));
	nvgText(vg, x+w/2,y+16+1, title, NULL);

	nvgFontBlur(vg,0);
	nvgFillColor(vg, nvgRGBA(220,220,220,160));
	nvgText(vg, x+w/2,y+16,  title, NULL);

	nvgRestore(vg);	
}