#include "../include/text_window.hpp"

TextWindow* TextWindow::mSingleton = NULL;
TextWindow::TextWindow
(
	const int& pWidth,
	const int pHeight,
	const Gorgon::Graphic::Color& pColor
) : Gorgon::Graphic::Image(pWidth,pHeight,32)
{
	mTextColor = pColor;
}

TextWindow::~TextWindow(){}

void TextWindow::init
(
	const int& pWidth,
	const int pHeight,
	const Gorgon::Graphic::Color& pColor
)
{
	if(!mSingleton)
	{
		mSingleton = new TextWindow
		(
			pWidth,
			pHeight,
			pColor
		);
	}
}

void TextWindow::halt()
{
	if(mSingleton)
	{
		delete mSingleton;
		mSingleton = NULL;
	}
}

TextWindow& TextWindow::get()
{
	init();
	return *mSingleton;
}

void TextWindow::add(const std::string& pString)
{
	blitImage(*this,Gorgon::Point(0,0),Gorgon::Point(0,10),getWidth(),getHeight());
	drawRectangle
	(
		Gorgon::Point(0, getHeight() - 10),
		Gorgon::Point(getWidth(),getHeight()),
		makecol(255,0,255),
		true
	);
	drawText(pString,0,getHeight()-10,mTextColor.get());
}

void TextWindow::add(const char* pText, ...)
{
	char buf[512];
	va_list ap;

	ASSERT(pText);
	va_start(ap,pText);
	uvszprintf(buf,sizeof(buf),pText,ap);
	va_end(ap);
	add(std::string(buf));
}

void TextWindow::show() const
{
	Gorgon::Graphic::Video::get().drawImage(*this,Gorgon::Point(0,0));
}
