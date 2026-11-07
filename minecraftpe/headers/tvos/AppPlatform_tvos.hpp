#pragma once
#ifdef __APPLE__
#include <AppPlatform.hpp>
#include <functional>

//Apple TV platform. The app shell (TVCraft's tvos/Sources) owns the window, the GL context and the input;
//this only answers the game. Construct it with the GL context current: AppPlatform's constructor reads GL_EXTENSIONS.
//Paths are relative to the app bundle's resources, which the shell makes the working directory (like the SDL build's cwd).
struct AppPlatform_tvos : AppPlatform{
	int32_t screenWidth, screenHeight;
	std::string textboxText;

	//set by the shell: show tvOS's keyboard for a text box (the game's current text, its max length), and hide it
	std::function<void(const std::string&, int32_t)> onShowKeyboard;
	std::function<void()> onHideKeyboard;

	//The platform dialogs the game polls (Android shows native ones): showDialog(id), createUserInput(), then getUserInputStatus()
	//until it is 0 (cancelled) or 1 (done) and getUserInput(). Dialog 1 creates a world: {name, seed, "survival" or "creative"};
	//4 renames one: {name}. 2 is the chat screen's, which types through showKeyboard instead.
	enum { DIALOG_CREATE_WORLD = 1, DIALOG_CHAT = 2, DIALOG_RENAME_WORLD = 4 };
	int32_t dialogId = 0;
	int32_t userInputStatus = -1;
	std::vector<std::string> userInput;
	std::function<void(int32_t)> onCreateUserInput;   //set by the shell: present dialog <id>, then call finishUserInput
	void finishUserInput(int32_t status, const std::vector<std::string>& input);
	virtual void showDialog(int32_t);
	virtual void createUserInput(void);
	virtual int32_t getUserInputStatus(void);
	virtual std::vector<std::string> getUserInput(void);

	AppPlatform_tvos(int32_t width, int32_t height);
	void setScreenSize(int32_t width, int32_t height);

	virtual std::string getImagePath(const std::string&, bool_t);
	virtual void loadPNG(ImageData&, const std::string&, bool_t);
	virtual AssetFile readAssetFile(const std::string& path);
	virtual int32_t getScreenWidth(void);
	virtual int32_t getScreenHeight(void);
	virtual bool supportsTouchscreen(void);
	virtual bool_t supportsVibration(void);
	virtual std::string getDateString(int32_t);
	virtual LoginInformation getLoginInformation(void);
	virtual void showKeyboard(const std::string&, int32_t, bool_t);
	virtual void hideKeyboard(void);
	virtual void updateTextBoxText(const std::string&);
	virtual void finish(void);
};
#endif
