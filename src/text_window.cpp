#include "../include/text_window.hpp"

TextWindow* TextWindow::mSingleton = NULL;
TextWindow::TextWindow
(
	const int& pWidth,
	const int pHeight,
	const Gorgon::Color& pColor
) : Gorgon::Image(pWidth,pHeight,32)
{
	mTextColor = pColor;
}

TextWindow::~TextWindow(){}

void TextWindow::init
(
	const int& pWidth,
	const int pHeight,
	const Gorgon::Color& pColor
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
	blitImage(*this,0,0,0,10,getWidth(),getHeight());
	drawRectangle
	(
		0,
		getHeight() - 10,
		getWidth(),
		getHeight(),
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
	Gorgon::Video::get().drawImage(*this,0,0);
}
