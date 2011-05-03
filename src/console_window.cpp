#include "../include/console_window.hpp"

ConsoleWindow* ConsoleWindow::mSingleton = NULL;

gcn::AllegroInput*			input;
gcn::AllegroGraphics*		graphics;
gcn::AllegroImageLoader*	imageLoader;
gcn::Gui* 					gui;
gcn::Window*	 			top;
gcn::ImageFont* 			gFont;

gcn::TextBox* textBox;
gcn::Label* label;

ConsoleWindow::ConsoleWindow()
{
	imageLoader		= new gcn::AllegroImageLoader();
	gcn::Image::setImageLoader(imageLoader);
	graphics		= new gcn::AllegroGraphics();
	graphics->setTarget(Gorgon::Graphic::Video::get().getImg());
	input			= new gcn::AllegroInput();
	gui 			= new gcn::Gui();
	gui->setGraphics(graphics);
	gui->setInput(input);
	
	//gFont 			= new gcn::ImageFont("fixedfont.bmp", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-:+./_");
	
	gFont = new gcn::ImageFont("font.bmp", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?-+/():;%&`'*#=[]\"<>{}^~|_@$\\");
	gcn::Widget::setGlobalFont(gFont); 
	
	top = new gcn::Window("Lua Console");
	top->setMovable(false);
	top->setDimension(gcn::Rectangle(0,0,Gorgon::Graphic::Video::get().getWidth(),Gorgon::Graphic::Video::get().getHeight()));
	gui->setTop(top);
	
	textBox = new gcn::TextBox("");
	textBox->setPosition(0, 0);
	top->add(textBox); 
	
	label = new gcn::Label("To execute your code hit F5.");
	label->setPosition(10,Gorgon::Graphic::Video::get().getHeight()- 40);
	top->add(label);
}

ConsoleWindow::~ConsoleWindow()
{
	delete label;
	delete textBox;
	delete top;
	delete gui;
	delete gFont;
	delete input;
	delete graphics;
	delete imageLoader;
}

ConsoleWindow& ConsoleWindow::get()
{
	if(mSingleton == NULL)
	{
		mSingleton= new ConsoleWindow();
	}
	return *mSingleton;
}

void ConsoleWindow::halt()
{
	if(mSingleton != NULL)
	{
		delete mSingleton;
		mSingleton = NULL;
	}
}

void ConsoleWindow::logic()
{
	gui->logic();
	if(key[KEY_F5])
	{
		
	}
}

void ConsoleWindow::draw()
{
	textBox->setDimension
	(
		gcn::Rectangle
		(
			0,0,
			Gorgon::Graphic::Video::get().getWidth(),
			Gorgon::Graphic::Video::get().getHeight() - 40
		)
	);
	gui->draw();
}

void ConsoleWindow::run()
{
	textBox->setEnabled(true);
	textBox->requestFocus();
}

void ConsoleWindow::stop()
{
	textBox->setEnabled(false);	
}

std::string ConsoleWindow::getText() const
{
	return textBox->getText();
}
