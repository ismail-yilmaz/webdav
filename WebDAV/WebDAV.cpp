#include "WebDAV.h"

namespace Upp {

namespace {

constexpr const char *sLockRequest =
								"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
									"<D:lockinfo xmlns:D=\"DAV:\">"
									"<D:lockscope><D:%s/></D:lockscope>"
									"<D:locktype><D:write/></D:locktype>"
									"<D:owner><D:href>%s</D:href></D:owner>"
									"</D:lockinfo>";

}

WebDAVRequest::WebDAVRequest()
{
}

WebDAVRequest::WebDAVRequest(const String& host, int port)
: HttpRequest()
{
	Host(host);
	Port(port);
}

WebDAVRequest::~WebDAVRequest()
{
}

void WebDAVRequest::StartGetDAVOptions()
{
	New();
	Method(HttpRequest::METHOD_OPTIONS, "OPTIONS");
}

void WebDAVRequest::StartLoadFile(const String& path)
{
	New();
	Path(path);
	Method(HttpRequest::METHOD_GET);
}

void WebDAVRequest::StartLoadFile(const String& path, String& data)
{
	New();
	Path(path);
	Method(HttpRequest::METHOD_GET);
	WhenContent = [&data](const void *out, int size) { data.Cat((const char*) out, size); };
}

void WebDAVRequest::StartLoadFile(const String& path, Stream& out)
{
	New();
	Path(path);
	Method(HttpRequest::METHOD_GET);
	WhenContent = [&out](const void *data, int size) { out.Put(data, size); };
}

void WebDAVRequest::StartSaveFile(const String& path, const String& data, const String& content_type)
{
	New();
	Path(path);
	Method(HttpRequest::METHOD_POST, "PUT");
	ContentType(content_type);
	PostData(data);
}

void WebDAVRequest::StartSaveFile(const String& path, Stream& in, const String& content_type)
{
	New();
	Path(path);
	Method(HttpRequest::METHOD_POST, "PUT");
	ContentType(content_type);
	PostStream(in);
}

void WebDAVRequest::StartDelete(const String& path)
{
	New();
	Path(path);
	Method(HttpRequest::METHOD_DELETE);
}

void WebDAVRequest::StartMakeDir(const String& path)
{
	New();
	Path(path);
	Method(HttpRequest::METHOD_PUT, "MKCOL");
}

void WebDAVRequest::StartCopy(const String& from, const String& to, bool overwrite, int depth)
{
	New();
	Path(from);
	Method(HttpRequest::METHOD_PUT, "COPY");
    Header("Destination", to);
    Header("Overwrite", overwrite ? "T" : "F");
    if(depth >= 0)
        Header("Depth", depth == 0 ? "0" : "infinity");
}

void WebDAVRequest::StartMove(const String& from, const String& to, bool overwrite)
{
	New();
	Path(from);
	Method(HttpRequest::METHOD_PUT, "MOVE");
    Header("Destination", to);
    Header("Overwrite", overwrite ? "T" : "F");
}

void WebDAVRequest::StartPropFind(const String& path, int depth, const String& props)
{
	New();
	Path(path);
	Method(HttpRequest::METHOD_POST, "PROPFIND");
	Header("Depth", AsString(depth));
	ContentType("application/xml; charset=utf-8");
	PostData(props);
}

void WebDAVRequest::StartPropPatch(const String& path, const String& xml)
{
	New();
	Path(path);
	Method(HttpRequest::METHOD_PATCH, "PROPPATCH");
	ContentType("application/xml; charset=utf-8");
	PostData(xml);
}

void WebDAVRequest::StartLock(const String& path, int timeout, const String& owner, bool exclusive)
{
	New();
	Path(path);
	Method(HttpRequest::METHOD_POST, "LOCK");
	ContentType("application/xml; charset=utf-8");
    Header("Timeout", Format("Second-%d", timeout));
    String ownerinfo = IsNull(owner) ? "" : owner;
    String lockscope = exclusive ? "exclusive" : "shared";
    String req = Format(sLockRequest, lockscope, ownerinfo);
	PostData(req);
}

void WebDAVRequest::StartUnlock(const String& path, const String& lock_token)
{
	New();
	Path(path);
	Method(HttpRequest::METHOD_POST, "UNLOCK");
	Header("Lock-Token", Format("<%s>", lock_token));
}

void WebDAVRequest::StartRefreshLock(const String& path, const String& lock_token, int timeout)
{
	New();
	Path(path);
	Method(HttpRequest::METHOD_POST, "LOCK");
	Header("If", Format("(<%s>)", lock_token));
	Header("Timeout", Format("Second-%d", timeout));
}

String WebDAVRequest::GetDAVOptions()
{
	StartGetDAVOptions();
	Execute();
	return HttpRequest::GetHeader("allow");
}

String WebDAVRequest::LoadFile(const String& path)
{
	StartLoadFile(path);
	return Execute();
}

bool WebDAVRequest::LoadFile(const String& path, String& data)
{
	StartLoadFile(path, data);
	return IsSuccess();
}

bool WebDAVRequest::LoadFile(const String& path, Stream& out)
{
	StartLoadFile(path, out);
	return IsSuccess();
}

bool WebDAVRequest::SaveFile(const String& path, const String& data, const String& content_type)
{
	StartSaveFile(path, data, content_type);
	Execute();
	return IsSuccess();
}

bool WebDAVRequest::SaveFile(const String& path, Stream& in, const String& content_type)
{
	StartSaveFile(path, in, content_type);
	Execute();
	return IsSuccess();
}

bool WebDAVRequest::Delete(const String& path)
{
	StartDelete(path);
	Execute();
	return IsSuccess();
}

bool WebDAVRequest::MakeDir(const String& path)
{
	StartMakeDir(path);
	Execute();
	return IsSuccess();
}

bool WebDAVRequest::Copy(const String& from, const String& to, bool overwrite, int depth)
{
	StartCopy(from, to, overwrite, depth);
	Execute();
	return IsSuccess();
}

bool WebDAVRequest::Move(const String& from, const String& to, bool overwrite)
{
	StartMove(from, to, overwrite);
	Execute();
	return IsSuccess();
}

String WebDAVRequest::PropFind(const String& path, int depth, const String& props)
{
	StartPropFind(path, depth, props);
	return Execute();
}

bool WebDAVRequest::PropPatch(const String& path, const String& xml)
{
	StartPropPatch(path, xml);
	return IsSuccess();
}

String WebDAVRequest::Lock(const String& path, int timeout, const String& owner, bool exclusive)
{
	StartLock(path, timeout, owner, exclusive);
	return Execute();
}

bool WebDAVRequest::Unlock(const String& path, const String& lock_token)
{
	StartUnlock(path, lock_token);
	Execute();
	return IsSuccess();
}

bool WebDAVRequest::RefreshLock(const String& path, const String& lock_token, int timeout)
{
	StartRefreshLock(path, lock_token, timeout);
	Execute();
	return IsSuccess();
}
	
}