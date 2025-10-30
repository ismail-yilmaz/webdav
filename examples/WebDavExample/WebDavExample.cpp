#include <Core/Core.h>
#include <WebDAV/WebDAV.h>

using namespace Upp;

void TestGetOptions(WebDAVRequest& dav)
{
	String options = dav.GetDAVOptions();
	if(dav.IsSuccess())
		LOG("Server supports: " << options);
	else
		LOG("GetDAVOptions failed: " << dav.GetErrorDesc());
}

void TestMakeDir(WebDAVRequest& dav, const String& path)
{
	if(dav.MakeDir(path))
		LOG("Directory created: " << path);
	else
		LOG("MakeDir failed: " << dav.GetErrorDesc()
		    << " (code: " << dav.GetStatusCode() << ")");
}

void TestSaveFile(WebDAVRequest& dav, const String& path, const String& content)
{
	if(dav.SaveFile(path, content, "text/plain"))
		LOG("File saved: " << path);
	else
		LOG("SaveFile failed: " << dav.GetErrorDesc());
}

void TestLoadFile(WebDAVRequest& dav, const String& path)
{
	String content = dav.LoadFile(path);
	if(dav.IsSuccess())
		LOG("File loaded: " << path << "\n" << content);
	else
		LOG("LoadFile failed: " << dav.GetErrorDesc());
}

void TestPropFind(WebDAVRequest& dav, const String& path, int depth = 1)
{
	String props = dav.PropFind(path, depth);
	if(dav.IsSuccess())
		LOG("Properties for " << path << " are retrieved");
	else
		LOG("PropFind failed: " << dav.GetErrorDesc());
}

void TestDelete(WebDAVRequest& dav, const String& path)
{
	if(dav.Delete(path))
		LOG("Deleted: " << path);
	else
		LOG("Delete failed: " << dav.GetErrorDesc());
}

CONSOLE_APP_MAIN
{
	// Note that this example requires a local WebDAV server.
	// Example: chezdav --local -v  --port 8080 --path /path/to/dir
	
	StdLogSetup(LOG_FILE|LOG_COUT);

	WebDAVRequest dav("localhost", 8080);
//	dav.Trace();

	TestGetOptions(dav);
	TestMakeDir(dav, "/documents");
	TestSaveFile(dav, "/documents/test.txt", "Hello, WebDAV!\nThis is a test file.");
	TestLoadFile(dav, "/documents/test.txt");
	TestPropFind(dav, "/documents");
	TestDelete(dav, "/documents/test.txt");
	TestDelete(dav, "/documents");
}