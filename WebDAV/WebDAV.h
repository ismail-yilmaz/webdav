#ifndef _WebDAV_WebDAV_h_
#define _WebDAV_WebDAV_h_

#include <Core/Core.h>
#include <Core/SSL/SSL.h>

namespace Upp {

class WebDAVRequest : public HttpRequest {
public:
	WebDAVRequest();
	WebDAVRequest(const String& host, int port = 80);
	virtual ~WebDAVRequest();
	
	// Non blocking initializers (use with Do() method)
	void    StartGetDAVOptions();
	void    StartLoadFile(const String& path);
	void    StartLoadFile(const String& path, String& data);
	void    StartLoadFile(const String& path, Stream& out);
	void    StartSaveFile(const String& path, const String& data, const String& content_type = "application/octet-stream");
	void    StartSaveFile(const String& path, Stream& in, const String& content_type = "application/octet-stream");
	void    StartDelete(const String& path);
	void    StartMakeDir(const String& path);
	void    StartCopy(const String& from, const String& to, bool overwrite = true, int depth = -1);
	void    StartMove(const String& from, const String& to, bool overwrite = true);
	void    StartPropFind(const String& path, int depth = 1, const String& props = Null);
	void    StartPropPatch(const String& path, const String& xml);
	void    StartLock(const String& path, int timeout = 100, const String& owner = Null, bool exclusive = true);
	void    StartUnlock(const String& path, const String& lock_token);
	void    StartRefreshLock(const String& path, const String& lock_token, int timeout = 100);
	void    StartReport(const String& path, const String& xmlquery);
	
	// Blocking variants
	String  GetDAVOptions();
	String  LoadFile(const String& path);
	bool    LoadFile(const String& path, String& data);
	bool    LoadFile(const String& path, Stream& out);
	bool    SaveFile(const String& path, const String& data, const String& content_type = "application/octet-stream");
	bool    SaveFile(const String& path, Stream& in, const String& content_type = "application/octet-stream");
	bool    Delete(const String& path);
	bool    MakeDir(const String& path);
	bool    Copy(const String& from, const String& to, bool overwrite = true, int depth = -1);
	bool    Move(const String& from, const String& to, bool overwrite = true);
	String  PropFind(const String& path, int depth = 1, const String& props = Null);
	bool    PropPatch(const String& path, const String& xml);
	String  Lock(const String& path, int timeout = 100, const String& owner = Null, bool exclusive = true);
	bool    Unlock(const String& path, const String& lock_token);
	bool    RefreshLock(const String& path, const String& lock_token, int timeout = 100);
	String  Report(const String& path, const String& xmlquery);
};

}
#endif
