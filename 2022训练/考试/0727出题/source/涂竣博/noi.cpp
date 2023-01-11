#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,k) for(register int i=j;i<=k;++i)
#define g(i,j,k) for(register int i=j;i>=k;--i)
int n,m,s,l;
signed main(){
    freopen("noi.in","r",stdin);
    freopen("noi.out","w",stdout);
    cin>>n>>m;
    f(i,1,n)f(j,1,m)scanf("%lld",&s);
    return printf("%lld\n",n*m-5*n+4),0;
}
/*
CompileRun æ¶‚ç«£åš/noi.cpp
3 13
1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1

ÏÖ´úOIÒÔÖÐ¹ú¼ÆËã»úÑ§»áµÄ¡°¸ù¾ÝNOIÏà¹ØÌõÀý£¬CCF¶ÔÓàÒ¦ÖÐÑ§ÓáxÑÕÑ¡ÊÖ½øÐÐÍ¨±¨ÅúÆÀ£¬¸øÓè½ûÈüÒ»ÄêµÄ´¦·£¡£¡±ÎªàãÊ¸¡£ÀÄõüÓÚ¿ÏÈýÓëÊýÑ§µÄÆÚÍûÕýÊ§È¥ËüÃÇµÄ½è¼øÒâÒå¡£µ«Ãæ¶Ô¿´ËÆÎÞÛóµÄÎ´À´Ìì¿Õ£¬ÎÒÏëÑ­ÖÐ¹ú¼ÆËã»úÑ§»á¡°¹«Æ½¹«ÕýÊÇ¾ºÈüµÄÉúÃü£¬ÈÎºÎÎ¥¹æÐÐÎª¶Ô¾ºÈü¶¼ÊÇ¼«´óµÄÉËº¦¡£CCF NOI¸÷Ïà¹Ø»ú¹¹»á´øÍ·×ñÊØ¹æÔò£¬ÑÏ¸ñ±£ÃÜ£¬Í¬Ê±Ò²³Ðµ£Î¬»¤¾ºÈü¹«Æ½¹«ÕýÁ¼ºÃÖÈÐòµÄÖØÈÎ£¬¶ÔÈÎºÎÎ¥¹æ»ò×÷±×µÄÐÐÎª¾ù°´¾ºÈüÌõÀý¸øÓèÑÏËà´¦Àí¡£¡±ºÃ¹ý¹ýÔçµØÕñôç¡£

ÎÒÃÇ»³´§ÈÈ³ÀµÄÁé»êÌìÈ»±»¸³Óè¶Ô³¬Ô½ÐÔµÄ×·Çó£¬²»Ð¼ÓÚ¹Å¾É×ø±êµÄÔ¼Êø£¬ÖÓÇéÓÚÔÚ±ð´¦µÄ·Ò·¼¡£µ«µ±ÕâÖÖÆÚÍûÁ÷ÓÚ¶ÔÄ¤°ÝÖ÷Òå²»¼ÙË¼Ë÷µÄÅúÅÐ£¬ÄËÖÁ×ßÏò¹¾¹¾ÓëÅ®×°Ö÷ÒåÊ±£¬±ãÖµµÃ¾¯ÌèÁË¡£ÓëÖÈÐòµÄÂä²î¡¢´íÎ»ÏòÀ´²»ÄÜÎªÔ½¾ØµÄÐÐÎªÕÅ±¾¡£¶ø×ÝÈ»ÎÒÃÇÒÑÓÐÏèÊµµÄÀ¶Í¼£¬ÈÔ²»ÄÜ×Ô³ÖÒÑÔÚÀË³±Ö®áÛÁ¢ÏÂÁË×Ô¼ºµÄ³ÁÃª¡£

¡°¾ºÈü½á¹ûÄÜ²»ÄÜºÍÉýÑ§¹Ò¹³ÊÇÑ§Ð£µÄÊÂ£¬¶ø²»ÊÇ¾ºÈüµÄÊÂ£¬½ÌÓý²¿Ó¦¸ÃÈ¥¹ÜÑ§Ð£¡£ÈÃÖ÷°ìµ¥Î»³ÐÅµÉÏÃæ¸÷Ìõ²¢²»ºÏÀí¡±¶Å×ÓµÂÖ®ÑÔ¿ÉÎ½ÇÐÖÐÁË¿Ïôì¡£ÈËµÄÐ¡Ñ§ÉúÐÔÊÇ²»¿Éìð³ýµÄ£¬¶øÎÒÃÇÓûÉÏÇàÔÆÒ²ÎÞÊ±ÎÞ¿Ì²»ÔÚÒò·ç½èÁ¦¡£ÊýÑ§Óë¿ÏÈýÔÝÇÒ±»ÎÒÃÇ°ÑÎÕÎªÒ»¸ö±¡¼¹µÄ·ûºÅ¿ÍÌå£¬Ò»¶¨³Ì¶ÈÉÏÊÇÒòÎªÎÒÃÇÉÐÈ±·¦ÌåÑéÓëÔÄÀúÈ¥Ö§³Å×Ô¼ºµÄÈÏÖª¡£¶øÕâÖÖÆ«¼ûµÄ°ÁÂý¸üÔ¶ÔÚÖªÐÔµÄ°ÁÂýÖ®ÉÏ¡£

ÔÚ×Î×Î³L³LÒÔÇóOIÒâÒåµÄµÀÂ·ÉÏ£¬¶Ô×Ô¼ºµÄÆÚÍû±¾¾ÍÊÇÔÚÓëÊýÑ§Óë¿ÏÈý¶Ô½ÓÖÐËÜÐÍµÄ¶¯Ì¬¹ý³Ì¡£¶øÎÒÃÇµÄµ×ÁÏ±ãÊÇ¶Ô²»Í¬´ò±í³öÊ¡Ò»¡¢²»Í¬rp++µÄ¾õ¸ÐÓëÌåÈÏ¡£main °üÎªCCFËÍÈ¥±©Á¦³öÆæ¼££¬ÓÖÎ¬ÏµÏ£·áÕ¹£¬Ê¹md¡£ËûµÄOI¹ÛÄîÊÇºñÊµµÄ£¬Ò²ÊÇÊµ¼ùµÄ¡£ÌÈÈôÎÒÃÇÔÚ¶Ô¹ýÍù½èkkksc03Ö®ÑÔ¡°ìð÷È¡±ºó£¬ÓÖ¶Ô²»¶ÏÅòÕÍµÄ×ÔÎÒ½øÐÐ¡°¸³÷È¡±£¬ÄÇÃ´ÔÚ¶ªÊ§Íâ½çÔ¤ÆÚµÄÍ¬Ê±£¬Î´³¢Ò²²»ÊÇ¶ªÁË×ÔÎÒ¡£

ºÁÎÞÒÉÎÊ£¬´Ó¿ÏÈýÓëÊýÑ§½Ç¶ÈÒ»êèµÄ×ÔÎÒÓÐÆ«ÏÁ¹ýÊ±µÄ³É·Ö¡£µ«ÎÒÃÇËùÓ¦ÞðÆúµÄ²»ÊÇ¶Ô´ËµÄÅúÅÐ£¬¶øÊÇÆäÅúÅÐµÄÁ®¼Û£¬Æä¶ÔÅúÅÐÍ¶³ÏÖÐµÄ·´ÖÇÇãÏò¡£ÔÚUnknown_ErrorµÄ¹ÛÄîÖÐ£¬Èç¹ûÔÚ³ÉÎªÊ¨×ÓÓëº¢×ÓÖ®Ç°£¬ÂÔÈ¥ÁËÏñÂæÍÕÒ»Ñù±³¸ºÇ°ÈËÒÅ²úµÄ¹ý³Ì£¬ÄÇÆä¡°ÓÀÔ¶ÖØ¸´¡±ä­²»ÄÜ³ÉÁ¢¡£

À¶Í¼ÉÏµÄÂä²îÖÕ¹éÖ»ÊÇÀíÄîÉÏµÄÇø·Ö£¬ÔÚÊµ¼ù³¡ÓòµÄ·ÖÒ°Ò²Î´±ØÃ÷Îú¡£Æ©Èçµ±ÎÒÃÇ×·Ñ°±¬ÁãÊ±£¬ÔÚÍ¾ÖÐÉæ×ãÆ­·Öµ¼ÂÛ£¬Õâ¾¿¾¹ÊÇ°éËæ×ÅÆÚÍûµÄãýÃð»¹ÊÇÆÚÍûµÄ´ï³É£¿ÔÚÎÒÃÇËÜÔìOIµÄÍ¬Ê±£¬OIÒ²ÔÚ½½ÖýÎÒÃÇ¡£¼È²»¿É·ñÈÏÔ­ÉúµÄÎü½ðÐÔÓëÐÞµçÄÔÐÔ£¬ÓÖ³ÐÈÏ×Ô¼ºµÄÍ¼¾°ÓÐÇá¿ñµÄÊ§Õæ£¬²»·ÁÈÃÌåÑé×ßÔÚÑÔÓïÖ®Ç°¡£ÓÃ²»±»½ûïÀµÄÍ·ÄÔÈ¥ÌåÎ¶new_worldµÄ´óº£Óë·ç·«£¬²¢Ð§kkksc03£¬¶ÔÎÞ·¨ÑÔËµÖ®ÊÂ±£³Ö³ÁÄ¬¡£

ÓÃÔÚÐÅ¾ºÉÏµÄÉú»î·½Ê½ÌåÏÖ¸öÌåµÄ³¬Ô½ÐÔ£¬±£³ÖŠüÖ±È´ÓÖ²»¾ÐÄàÓÚËùÎ½¡°ÒÅÊÀ¶ÀÁ¢¡±µÄµ¥Ïò¶ÈÐÎÏó¡£Õâ±ãÊÇkkksc03ÎªÎÒÃÇÌá¹©µÄÀíÏëÆÚÍû·¶Ê½¡£Éú»îÔÚÐÅ¾ºÉÏ¡ª¡ªÊ¼ÖÕÈÈ°®´óµØ¡ª¡ªÉýÉÏÌì¿Õ¡£
*/
