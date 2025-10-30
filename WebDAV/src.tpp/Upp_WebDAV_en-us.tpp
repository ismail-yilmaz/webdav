topic "WebDAVRequest";
[i448;a25;kKO9;2 $$1,0#37138531426314131252341829483380:class]
[l288;2 $$2,2#27521748481378242620020725143825:desc]
[0 $$3,0#96390100711032703541132217272105:end]
[H6;0 $$4,0#05600065144404261032431302351956:begin]
[i448;a25;kKO9;2 $$5,0#37138531426314131252341829483370:item]
[l288;a4;*@5;1 $$6,6#70004532496200323422659154056402:requirement]
[l288;i1121;b17;O9;~~~.1408;2 $$7,0#10431211400427159095818037425705:param]
[i448;b42;O9;2 $$8,8#61672508125594000341940100500538:tparam]
[b42;2 $$9,9#13035079074754324216151401829390:normal]
[2 $$0,0#00000000000000000000000000000000:Default]
[{_} 
[ {{10000@(113.42.0) [s0;%% [*@7;4 WebDAVRequest]]}}&]
[s0; &]
[s1;:Upp`:`:WebDAVRequest: [@(0.0.255)3 class][3  ][*3 WebDAVRequest][3  
][@(0.0.255)3 :][3  ][@(0.0.255)3 public][3  HttpRequest]&]
[s2;%% This class is a WebDAV client`-side implementation that extends 
[^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:class^ HttpRequest 
]class to provide WebDAV protocol support. It offers both blocking 
and non`-blocking operation modes for all WebDAV operations.&]
[s3;%% &]
[ {{10000F(128)G(128)@1 [s0;%% [* Constructor detail]]}}&]
[s3; &]
[s5;:Upp`:`:WebDAVRequest`:`:WebDAVRequest`(`): [* WebDAVRequest]()&]
[s2;%% Default constructor.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:WebDAVRequest`(const String`&`,int`): [* WebDAVRequest]([@(0.0.255) c
onst] String[@(0.0.255) `&] [*@3 host], [@(0.0.255) int] [*@3 port] [@(0.0.255) `=] 
[@3 80])&]
[s2;%% Constructs with the specified [%-*@3 host] and [%-*@3 port] . 
The host parameter is the server hostname or IP address, and 
port is the server port.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Non`-Blocking Methods]]}}&]
[s3; &]
[s2; Non`-blocking methods begins with Start prefix and initialize 
the given operation. Use [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:Do`(`)^ D
o()] method to drive the operation to completion. Check [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:IsSuccess`(`)const^ I
sSuccess()] after completion to verify the operation succeeded.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:StartGetDAVOptions`(`): [@(0.0.255) void] 
[* StartGetDAVOptions]()&]
[s2;%% Starts retrieving server capabilities. After a successful 
completion, check the `"[C@3 Allow]`" header for supported methods.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:StartLoadFile`(const String`&`): [@(0.0.255) void] 
[* StartLoadFile]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Starts downloading a file from the specified [%-*@3 path]. [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:GetContent`(`)const^ G
etContent()] method can be used to retrieve the data after a 
successful completion. Or [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:WhenContent^ W
henContent] event can be used to redirect the output.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:StartSaveFile`(const String`&`,const String`&`,const String`&`): [@(0.0.255) v
oid] [* StartSaveFile]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 data], [@(0.0.255) const] 
String[@(0.0.255) `&] [*@3 content`_type] [@(0.0.255) `=] `"[C@3 application/octet`-strea
m]`")&]
[s2;%% Starts uploading string [%-*@3 data ]to the specified [%-*@3 path] 
with given [%-*@3 content`_type].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:StartSaveFile`(const String`&`,Stream`&`,const String`&`): [@(0.0.255) v
oid] [* StartSaveFile]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
Stream[@(0.0.255) `&] [*@3 in], [@(0.0.255) const] String[@(0.0.255) `&] 
[*@3 content`_type] [@(0.0.255) `=] `"[C@3 application/octet`-stream]`")&]
[s2;%% Starts uploading the [%-*@3 in ]stream to the specified [%-*@3 path] 
with given [%-*@3 content`_type].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:StartDelete`(const String`&`): [@(0.0.255) void] 
[* StartDelete]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Starts deletion of the resource at the specified [%-*@3 path].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:StartMakeDir`(const String`&`): [@(0.0.255) void] 
[* StartMakeDir]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Starts creation of a new directory (collection) at the specified 
[%-*@3 path].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:StartCopy`(const String`&`,const String`&`,bool`,int`): [@(0.0.255) v
oid] [* StartCopy]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 from], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 to], [@(0.0.255) bool] 
[*@3 overwrite] [@(0.0.255) `=] [@(0.0.255) true], [@(0.0.255) int] [*@3 depth] 
[@(0.0.255) `=] [@(0.0.255) `-][@3 1])&]
[s2;%% Starts copying a resource. The [%-*@3 from] parameter is the 
source path, [%-*@3 to] is the destination path and must be a full 
URL, [%-*@3 overwrite] determines whether to overwrite an existing 
resource, and depth specifies the copy [%-*@3 depth] where `-1 
means infinity for collections and 0 means resource only.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:StartMove`(const String`&`,const String`&`,bool`): [@(0.0.255) v
oid] [* StartMove]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 from], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 to], [@(0.0.255) bool] 
[*@3 overwrite] [@(0.0.255) `=] [@(0.0.255) true])&]
[s2;%% Starts moving a resource. The [%-*@3 from] parameter is the 
source path, [%-*@3 to] is the destination path and must be a full 
URL, [%-*@3 overwrite] determines whether to overwrite an existing 
resource.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:StartPropFind`(const String`&`,int`,const String`&`): [@(0.0.255) v
oid] [* StartPropFind]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) int] [*@3 depth] [@(0.0.255) `=] [@3 1], [@(0.0.255) const] 
String[@(0.0.255) `&] [*@3 props] [@(0.0.255) `=] Null)&]
[s2;%% Starts property query. The [%-*@3 path] parameter specifies 
the resource path, [%-*@3 depth] specifies the query depth where 
0 means resource only, 1 means resource plus children, and `-1 
means infinite, and [%-*@3 props] is optional XML specifying properties 
to retrieve. If [%-*@3 props] is Null, the server returns default 
properties. [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:GetContent`(`)const^ G
etContent()] method can be used to retrieve the data after a 
successful completion. Or [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:WhenContent^ W
henContent] event can be used to redirect the output.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:StartPropPatch`(const String`&`,const String`&`): [@(0.0.255) v
oid] [* StartPropPatch]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 xml])&]
[s2;%% Starts property modification. The [%-*@3 path] parameter specifies 
the resource path, and [%-*@3 xml] contains the property changes 
in PROPPATCH format.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:StartLock`(const String`&`,int`,const String`&`,bool`): [@(0.0.255) v
oid] [* StartLock]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) int] [*@3 timeout] [@(0.0.255) `=] [@3 100], [@(0.0.255) const] 
String[@(0.0.255) `&] [*@3 owner] [@(0.0.255) `=] Null, [@(0.0.255) bool] 
[*@3 exclusive] [@(0.0.255) `=] [@(0.0.255) true])&]
[s2;%% Starts resource locking. The path parameter specifies the 
resource [%-*@3 path] , [%-*@3 timeout] is the lock timeout in seconds, 
owner is an optional lock [%-*@3 owner] identifier, and [%-*@3 exclusive] 
determines whether the lock is exclusive or shared. [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:GetContent`(`)const^ G
etContent()] method can be used to retrieve the token after a 
successful completion. Or [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:WhenContent^ W
henContent] event can be used to redirect the output.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:StartUnlock`(const String`&`,const String`&`): [@(0.0.255) v
oid] [* StartUnlock]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 lock`_token])&]
[s2;%% Starts resource unlocking. The [%-*@3 path] parameter specifies 
the resource path, and [%-*@3 lock`_token]  is the token obtained 
from a lock operation.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:StartRefreshLock`(const String`&`,const String`&`,int`): [@(0.0.255) v
oid] [* StartRefreshLock]([@(0.0.255) const] String[@(0.0.255) `&] 
[*@3 path], [@(0.0.255) const] String[@(0.0.255) `&] [*@3 lock`_token], 
[@(0.0.255) int] [*@3 timeout] [@(0.0.255) `=] [@3 100])&]
[s2;%% Starts lock timeout refresh. The [%-*@3 path] parameter specifies 
the resource path, [%-*@3 lock`_token] is the token obtained from 
a Lock operation, and [%-*@3 timeout] is the new lock timeout in 
seconds.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Blocking Methods]]}}&]
[s3; &]
[s2; Blocking methods execute immediately and return when the operation 
completes.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:GetDAVOptions`(`): String [* GetDAVOptions]()&]
[s2;%% Returns server capabilities. Returns an empty string on failure.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:LoadFile`(const String`&`): String [* LoadFile]([@(0.0.255) c
onst] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Downloads a file from the server. The [%-*@3 path] parameter 
specifies the server path to the file. Returns the file content 
as a String.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:SaveFile`(const String`&`,const String`&`,const String`&`): [@(0.0.255) b
ool] [* SaveFile]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 data], [@(0.0.255) const] 
String[@(0.0.255) `&] [*@3 content`_type] [@(0.0.255) `=] `"[C@3 application/octet`-strea
m`"])&]
[s2;%% Uploads file content to the server using string data. The 
[%-*@3 path] parameter is the target path on the server, [%-*@3 data 
]contains the file content to upload, and [%-*@3 content`_type] 
specifies the MIME type. Returns true if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:SaveFile`(const String`&`,Stream`&`,const String`&`): [@(0.0.255) b
ool] [* SaveFile]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
Stream[@(0.0.255) `&] [*@3 in], [@(0.0.255) const] String[@(0.0.255) `&] 
[*@3 content`_type] [@(0.0.255) `=] `"[C@3 application/octet`-stream]`")&]
[s2;%% Uploads file content to the server using a stream. The [%-*@3 path] 
parameter is the target path on the server, [%-*@3 in] is the input 
stream containing file data, and [%-*@3 content`_type] specifies 
the MIME type. Returns true if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:Delete`(const String`&`): [@(0.0.255) bool] 
[* Delete]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Deletes a file or directory from the server. The [%-*@3 path] 
parameter specifies the resource to delete. Returns true if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:MakeDir`(const String`&`): [@(0.0.255) bool] 
[* MakeDir]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Creates a new directory (collection) on the server. The [%-*@3 path] 
parameter specifies the path for the new directory. Returns true 
if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:Copy`(const String`&`,const String`&`,bool`,int`): [@(0.0.255) b
ool] [* Copy]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 from], [@(0.0.255) const] 
String[@(0.0.255) `&] [*@3 to], [@(0.0.255) bool] [*@3 overwrite] [@(0.0.255) `=] 
[@(0.0.255) true], [@(0.0.255) int] [*@3 depth] [@(0.0.255) `=] [@(0.0.255) `-][@3 1])&]
[s2;%% Copies a file or directory on the server. The [%-*@3 from] parameter 
is the source path, [%-*@3 to] is the destination path and must 
be a full URL, [%-*@3 overwrite] determines whether to overwrite 
an existing resource, and [%-*@3 depth] specifies the copy depth 
where `-1 means infinity for collections and 0 means resource 
only. Returns true if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:Move`(const String`&`,const String`&`,bool`): [@(0.0.255) b
ool] [* Move]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 from], [@(0.0.255) const] 
String[@(0.0.255) `&] [*@3 to], [@(0.0.255) bool] [*@3 overwrite] [@(0.0.255) `=] 
[@(0.0.255) true])&]
[s2;%% Copies a file or directory on the server. The [%-*@3 from] parameter 
is the source path, [%-*@3 to] is the destination path and must 
be a full URL, [%-*@3 overwrite] determines whether to overwrite 
an existing resource. Returns true if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:PropFind`(const String`&`,int`,const String`&`): String 
[* PropFind]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], [@(0.0.255) int] 
[*@3 depth] [@(0.0.255) `=] [@3 1], [@(0.0.255) const] String[@(0.0.255) `&] 
[*@3 props] [@(0.0.255) `=] Null)&]
[s2;%% Queries resource properties. The [%-*@3 path] parameter specifies 
the resource path, [%-*@3 depth] specifies the query depth where 
0 means resource only, 1 means resource plus children, and `-1 
means infinite, and [%-*@3 props] is optional XML specifying properties 
to retrieve. If [%-*@3 props] is Null, the server returns default 
properties. Returns an XML string containing property information.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:PropPatch`(const String`&`,const String`&`): [@(0.0.255) b
ool] [* PropPatch]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 xml])&]
[s2;%% Modifies resource properties. The [%-*@3 path] parameter specifies 
the resource path, and [%-*@3 xml] contains the property changes 
in PROPPATCH format. Returns true if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:Lock`(const String`&`,int`,const String`&`,bool`): Strin
g [* Lock]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], [@(0.0.255) int] 
[*@3 timeout] [@(0.0.255) `=] [@3 100], [@(0.0.255) const] String[@(0.0.255) `&] 
[*@3 owner] [@(0.0.255) `=] Null, [@(0.0.255) bool] [*@3 exclusive] [@(0.0.255) `=] 
[@(0.0.255) true])&]
[s2;%% Locks a resource. The [%-*@3 path] parameter specifies the resource 
path, [%-*@3 timeout] is the lock timeout in seconds, owner is 
an optional lock [%-*@3 owner] identifier, and [%-*@3 exclusive] 
determines whether the lock is exclusive or shared. Returns the 
lock token string or an empty string on failure.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:Unlock`(const String`&`,const String`&`): [@(0.0.255) bool
] [* Unlock]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], [@(0.0.255) const] 
String[@(0.0.255) `&] [*@3 lock`_token])&]
[s2;%% Unlocks a previously locked resource. The [%-*@3 path] parameter 
specifies the resource path, and [%-*@3 lock`_token] is the token 
obtained from a lock operation. Returns true if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:WebDAVRequest`:`:RefreshLock`(const String`&`,const String`&`,int`): [@(0.0.255) b
ool] [* RefreshLock]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 lock`_token], [@(0.0.255) int] 
[*@3 timeout] [@(0.0.255) `=] [@3 100])&]
[s2;%% Refreshes lock timeout. The [%-*@3 path] parameter specifies 
the resource path, [%-*@3 lock`_token] is the token obtained from 
a lock operation, and [%-*@3 timeout] is the new lock timeout in 
seconds. Returns true if successful.&]
[s0; ]]