//---------------------------------------------------------------------------
#ifndef LiskApi_importH
#define LiskApi_importH
class LibLiskApi{
private:
	HINSTANCE  hdll;
public:
__stdcall LibLiskApi(UnicodeString path);
__stdcall ~LibLiskApi();
void __stdcall (*InitAPI)(char *nodeurl);
void __stdcall (*SetNodeURL)(char *nodeurl);
void __stdcall (*FreeAPI)();
char * __stdcall  (*GetAccountBySecret)(char * secret);
char * __stdcall  (*Balance)(char * address);
char * __stdcall  (*PublicKey)(char * address);
char * __stdcall  (*GenPublicKey)(char * secret);
char * __stdcall  (*GetAccountByAddress)(char * address);
char * __stdcall  (*GetDelegates)(char * address);
char * __stdcall  (*DelegatesVote)(char * secret,char * second_secret,char * pubkey,char *delegates);
char * __stdcall  (*Status)();
char * __stdcall  (*SyncStatus)();
char * __stdcall  (*Ping)();
char * __stdcall  (*Transations)(char * blockID,char * senderId,char * recvID,__int64 limit,__int64 offset,char * orderby);
char * __stdcall  (*SendTransactions)(char * secret,__int64 amount,char * recverID,char * publicKey,char * secondSecret);
char * __stdcall  (*GetTransactions)(char * txid);
char * __stdcall  (*GetUnConfirmedTxByID)(char * txid);
char * __stdcall  (*GetUnConfirmedTx)();
char * __stdcall  (*GetQueuedTx)();
char * __stdcall  (*GetQueuedTxByID)(char * txid);
char * __stdcall  (*GetPeers)(int state,char * os,char * version,int limit,__int32 offset,char * orderBy);
char * __stdcall  (*GetPeerByIPEndPoint)(char * ip,int port);
char * __stdcall  (*LisNodeVersion)();
char * __stdcall  (*GetBlockByID)(char * blockid);
char * __stdcall  (*GetBlocks)(__int64 totalfee,__int64 totalAmount,char * prevBlock,__int64 height,char * generatorPubKey,int limit,__int32 offset,char * orderBy);
char * __stdcall  (*GetBlockFee)();
char * __stdcall  (*GetFees)();
char * __stdcall  (*GetReward)();
char * __stdcall  (*GetSupply)();
char * __stdcall  (*GetHeight)();
char * __stdcall  (*GetStatus)();
char * __stdcall  (*GetNethash)();
char * __stdcall  (*GetMilestone)();
char * __stdcall  (*GetSignatureFee)();
char * __stdcall  (*AddSignature)(char * secret,char * secondSecret,char * publickey);
char * __stdcall  (*CreateDelegate)(char * secret,char * second_secret,char * username);
char * __stdcall  (*DelegatesList)(int limit,__int32 offset,char * orderBy);
char * __stdcall  (*GetDelegateByPkey)(char * publickey);
char * __stdcall  (*GetDelegateByName)(char * username);
char * __stdcall  (*SearchDelegate)(char * username,char * orderby);
char * __stdcall  (*DelegatesCount)();
char * __stdcall  (*GetVotesByAddress)(char * address);
char * __stdcall  (*GetVotersByPubkey)(char * publicKey);
char * __stdcall  (*EnableForge)(char * secret);
char * __stdcall  (*DisableForge)(char * secret);
char * __stdcall  (*GetForgedAmount)(char * pubkey);
char * __stdcall  (*GetNextForgers)(int limit);
char * __stdcall  (*RegistDapp)(char * secret,char * secondSecret,char * pubkey,char * category,char * name,char * description,char * tags,int type,char * link,char * icon);
char * __stdcall  (*GetDapps)(char * category,char * name,int type,char * link,int limit,__int32 offset,char * orderBy);
char * __stdcall  (*GetDapp)(char * id);
char * __stdcall  (*SearchDapp)(char * query,char * category,int isInstalled);
char * __stdcall  (*InstallDapp)(char * id);
char * __stdcall  (*InstalledDapps)();
char * __stdcall  (*InstalledDappIds)();
char * __stdcall  (*UninstallDapp)(char * id);
char * __stdcall  (*LaunchDapp)(char * id,char * params);
char * __stdcall  (*InstallingDapps)();
char * __stdcall  (*UnInstallingDapps)();
char * __stdcall  (*LaunchedDapps)();
char * __stdcall  (*Catefories)();
char * __stdcall  (*StopDapp)(char * id);
char * __stdcall  (*MultiSign)(char * secret,int lifetime,int min,char *keysgroup);
char * __stdcall  (*GetMultiSign)(char * publickey);
char * __stdcall  (*SignMultiSignature)(char * secret,char * publickey,char * txid);
char * __stdcall  (*GetPendingMultiSign)(char * publickey);
};
__stdcall LibLiskApi::LibLiskApi(UnicodeString path){
	hdll=LoadLibrary(path.c_str());
	InitAPI= (void __stdcall (*)(char *))GetProcAddress(hdll,"InitAPI");
	SetNodeURL=(void __stdcall (*)(char *nodeurl))GetProcAddress(hdll,"SetNodeURL");
	FreeAPI= (void __stdcall (*)(void))GetProcAddress(hdll,"FreeAPI");
	GetAccountBySecret=(char* __stdcall (*)(char *))GetProcAddress(hdll,"GetAccountBySecret");
	Balance=(char* __stdcall (*)(char *))GetProcAddress(hdll,"Balance");
	PublicKey=(char* __stdcall (*)(char *))GetProcAddress(hdll,"PublicKey");
	GenPublicKey=(char* __stdcall (*)(char *))GetProcAddress(hdll,"GenPublicKey");
	GetAccountByAddress=(char* __stdcall (*)(char *))GetProcAddress(hdll,"GetAccountByAddress");
	GetDelegates=(char* __stdcall (*)(char *))GetProcAddress(hdll,"GetDelegates");
	DelegatesVote=(char* __stdcall (*)(char * ,char * ,char * ,char *))GetProcAddress(hdll,"DelegatesVote");
	Status=(char* __stdcall (*)(void))GetProcAddress(hdll,"Status");
	SyncStatus=(char* __stdcall (*)(void))GetProcAddress(hdll,"SyncStatus");
	Ping=(char* __stdcall (*)(void))GetProcAddress(hdll,"Ping");
	Transations=(char* __stdcall (*)(char * ,char * ,char * ,__int64 ,__int64 ,char * ))GetProcAddress(hdll,"Transations");
	SendTransactions=(char* __stdcall (*)(char * ,__int64 ,char * ,char * ,char * ))GetProcAddress(hdll,"SendTransactions");
	GetTransactions=(char* __stdcall (*)(char *))GetProcAddress(hdll,"GetTransactions");
	GetUnConfirmedTxByID=(char* __stdcall (*)(char *))GetProcAddress(hdll,"GetUnConfirmedTxByID");
	GetUnConfirmedTx=(char* __stdcall (*)(void))GetProcAddress(hdll,"GetUnConfirmedTx");
	GetQueuedTx=(char* __stdcall (*)(void))GetProcAddress(hdll,"GetQueuedTx");
	GetQueuedTxByID=(char* __stdcall (*)(char *))GetProcAddress(hdll,"GetQueuedTxByID");
	GetPeers=(char* __stdcall (*)(int ,char * ,char * ,int ,__int32 ,char * ))GetProcAddress(hdll,"GetPeers");
	GetPeerByIPEndPoint=(char* __stdcall (*)(char *,int ))GetProcAddress(hdll,"GetPeerByIPEndPoint");
	LisNodeVersion=(char* __stdcall (*)())GetProcAddress(hdll,"LisNodeVersion");
	GetBlockByID=(char* __stdcall (*)(char * ))GetProcAddress(hdll,"GetBlockByID");
	GetBlocks=(char* __stdcall (*)(__int64 ,__int64 ,char * ,__int64 ,char * ,int ,__int32 ,char * ))GetProcAddress(hdll,"GetBlocks");
	GetBlockFee=(char* __stdcall (*)(void))GetProcAddress(hdll,"GetBlockFee");
	GetFees=(char* __stdcall (*)(void))GetProcAddress(hdll,"GetFees");
	GetReward=(char* __stdcall (*)(void))GetProcAddress(hdll,"GetReward");
	GetSupply=(char* __stdcall (*)(void))GetProcAddress(hdll,"GetSupply");
	GetHeight=(char* __stdcall (*)(void))GetProcAddress(hdll,"GetHeight");
	GetStatus=(char* __stdcall (*)(void))GetProcAddress(hdll,"GetStatus");
	GetNethash=(char* __stdcall (*)(void))GetProcAddress(hdll,"GetNethash");
	GetMilestone=(char* __stdcall (*)(void))GetProcAddress(hdll,"GetMilestone");
	GetSignatureFee=(char* __stdcall (*)(void))GetProcAddress(hdll,"GetSignatureFee");
	AddSignature=(char* __stdcall (*)(char * ,char * ,char * ))GetProcAddress(hdll,"AddSignature");
	CreateDelegate=(char* __stdcall (*)(char * ,char * ,char * ))GetProcAddress(hdll,"CreateDelegate");
	DelegatesList=(char* __stdcall (*)(int ,__int32 ,char * ))GetProcAddress(hdll,"DelegatesList");
	GetDelegateByPkey=(char* __stdcall (*)(char *))GetProcAddress(hdll,"GetDelegateByPkey");
	GetDelegateByName=(char* __stdcall (*)(char *))GetProcAddress(hdll,"GetDelegateByName");
	SearchDelegate=(char* __stdcall (*)(char * ,char * ))GetProcAddress(hdll,"SearchDelegate");
	DelegatesCount=(char* __stdcall (*)(void))GetProcAddress(hdll,"DelegatesCount");
	GetVotesByAddress=(char* __stdcall (*)(char *))GetProcAddress(hdll,"GetVotesByAddress");
	GetVotersByPubkey=(char* __stdcall (*)(char *))GetProcAddress(hdll,"GetVotersByPubkey");
	EnableForge=(char* __stdcall (*)(char *))GetProcAddress(hdll,"EnableForge");
	DisableForge=(char* __stdcall (*)(char *))GetProcAddress(hdll,"DisableForge");
	GetForgedAmount=(char* __stdcall (*)(char *))GetProcAddress(hdll,"GetForgedAmount");
	GetNextForgers=(char* __stdcall (*)(int))GetProcAddress(hdll,"GetNextForgers");
	RegistDapp=(char* __stdcall (*)(char * ,char * ,char * ,char * ,char * ,char * ,char * ,int ,char * ,char * ))GetProcAddress(hdll,"RegistDapp");
	GetDapps=(char* __stdcall (*)(char * ,char * ,int ,char * ,int ,__int32 ,char * ))GetProcAddress(hdll,"GetDapps");
	GetDapp=(char* __stdcall (*)(char *))GetProcAddress(hdll,"GetDapp");
	SearchDapp=(char* __stdcall (*)(char * ,char * ,int ))GetProcAddress(hdll,"SearchDapp");
	InstallDapp=(char* __stdcall (*)(char *))GetProcAddress(hdll,"InstallDapp");
	InstalledDapps=(char* __stdcall (*)(void))GetProcAddress(hdll,"InstalledDapps");
	InstalledDappIds=(char* __stdcall (*)(void))GetProcAddress(hdll,"InstalledDappIds");
	UninstallDapp=(char* __stdcall (*)(char *))GetProcAddress(hdll,"UninstallDapp");
	LaunchDapp=(char* __stdcall (*)(char * ,char * ))GetProcAddress(hdll,"LaunchDapp");
	InstallingDapps=(char* __stdcall (*)(void))GetProcAddress(hdll,"InstallingDapps");
	UnInstallingDapps=(char* __stdcall (*)(void))GetProcAddress(hdll,"UnInstallingDapps");
	LaunchedDapps=(char* __stdcall (*)(void))GetProcAddress(hdll,"LaunchedDapps");
	Catefories=(char* __stdcall (*)(void))GetProcAddress(hdll,"Catefories");
	StopDapp=(char* __stdcall (*)(char *))GetProcAddress(hdll,"StopDapp");
	MultiSign=(char* __stdcall (*)(char * ,int ,int ,char *))GetProcAddress(hdll,"MultiSign");
	GetMultiSign=(char* __stdcall (*)(char *))GetProcAddress(hdll,"GetMultiSign");
	SignMultiSignature=(char* __stdcall (*)(char * ,char * ,char * ))GetProcAddress(hdll,"SignMultiSignature");
	GetPendingMultiSign=(char* __stdcall (*)(char *))GetProcAddress(hdll,"GetPendingMultiSign");
}
__stdcall LibLiskApi::~LibLiskApi()
{
   FreeAPI();
   FreeLibrary(hdll);
}
#endif
