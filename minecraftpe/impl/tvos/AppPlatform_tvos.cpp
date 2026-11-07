#ifdef __APPLE__
#include <tvos/AppPlatform_tvos.hpp>
#include <stb_image.h>
#include <ImageData.hpp>
#include <time.h>
#include <stdio.h>

AppPlatform_tvos::AppPlatform_tvos(int32_t width, int32_t height)
	: AppPlatform()
	, screenWidth(width)
	, screenHeight(height) {
}
void AppPlatform_tvos::setScreenSize(int32_t width, int32_t height) {
	this->screenWidth = width;
	this->screenHeight = height;
}

std::string AppPlatform_tvos::getImagePath(const std::string& name, bool_t) {
	return "assets/images/" + name;
}
void AppPlatform_tvos::loadPNG(ImageData& data, const std::string& path, bool_t) {
	//as AppPlatform_sdl: Android decodes through Java, here stb_image does it
	int32_t channels;
	uint8_t* pixels = stbi_load(path.c_str(), &data.width, &data.height, &channels, STBI_rgb_alpha);
	if(!pixels) {
		//AppPlatform::loadTexture asks for name_mip1.png, _mip2... until one is missing: that one is expected
		if(path.find("_mip") == std::string::npos) printf("[RED] failed to load %s\n", path.c_str());
		return;
	}
	data.field_C = 0; //rgba
	data.pixels = pixels;
}
AssetFile AppPlatform_tvos::readAssetFile(const std::string& path) {
	return AppPlatform::readAssetFile("assets/" + path);
}
int32_t AppPlatform_tvos::getScreenWidth(void) {
	return this->screenWidth;
}
int32_t AppPlatform_tvos::getScreenHeight(void) {
	return this->screenHeight;
}
bool AppPlatform_tvos::supportsTouchscreen(void) {
	return 0;
}
bool_t AppPlatform_tvos::supportsVibration(void) {
	return 0;
}
std::string AppPlatform_tvos::getDateString(int32_t t) {
	time_t time = t;
	struct tm local;
	char buf[64];
	localtime_r(&time, &local);
	strftime(buf, sizeof(buf), "%b %d %Y %H:%M", &local);
	return buf;
}
LoginInformation AppPlatform_tvos::getLoginInformation(void) {
	return LoginInformation(); //no Mojang account: Realms is gone
}
void AppPlatform_tvos::showKeyboard(const std::string& text, int32_t maxLength, bool_t a4) {
	AppPlatform::showKeyboard(text, maxLength, a4);
	this->textboxText = text;
	if(this->onShowKeyboard) this->onShowKeyboard(text, maxLength);
}
void AppPlatform_tvos::hideKeyboard(void) {
	AppPlatform::hideKeyboard();
	if(this->onHideKeyboard) this->onHideKeyboard();
}
void AppPlatform_tvos::updateTextBoxText(const std::string& text) {
	this->textboxText = text;
}
void AppPlatform_tvos::showDialog(int32_t id) {
	this->dialogId = id;
}
void AppPlatform_tvos::createUserInput(void) {
	this->userInput.clear();
	if(this->dialogId == DIALOG_CHAT || !this->onCreateUserInput) {
		this->userInputStatus = this->dialogId == DIALOG_CHAT ? -1 : 0;
		return;
	}
	this->userInputStatus = -1; //asked: the screen polls until the shell answers
	this->onCreateUserInput(this->dialogId);
}
void AppPlatform_tvos::finishUserInput(int32_t status, const std::vector<std::string>& input) {
	this->userInput = input;
	this->userInputStatus = status;
}
int32_t AppPlatform_tvos::getUserInputStatus(void) {
	return this->userInputStatus;
}
std::vector<std::string> AppPlatform_tvos::getUserInput(void) {
	return this->userInput;
}
void AppPlatform_tvos::finish(void) {
	//tvOS apps do not quit themselves; the TV button leaves the game
}
#endif
