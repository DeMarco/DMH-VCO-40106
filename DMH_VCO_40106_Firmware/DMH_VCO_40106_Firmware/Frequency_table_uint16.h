#include <avr/pgmspace.h>
// [note][limits]
const uint16_t frequency_table[97][5] PROGMEM = {
{ 159	,	161		,	163		,	164		,	166		} ,
{ 168	,	171		,	173		,	174		,	176		} ,
{ 178	,	181		,	183		,	184		,	186		} ,
{ 189	,	192		,	194		,	195		,	197		} ,
{ 200	,	203		,	205		,	207		,	209		} ,
{ 212	,	215		,	218		,	219		,	222		} ,
{ 225	,	228		,	231		,	232		,	235		} ,
{ 238	,	242		,	244		,	246		,	249		} ,
{ 252	,	256		,	259		,	260		,	263		} ,
{ 267	,	271		,	274		,	276		,	279		} ,
{ 283	,	287		,	291		,	292		,	296		} ,
{ 300	,	304		,	308		,	310		,	313		} ,
{ 318	,	322		,	326		,	328		,	332		} ,
{ 337	,	342		,	346		,	348		,	352		} ,
{ 357	,	362		,	366		,	368		,	373		} ,
{ 378	,	383		,	388		,	390		,	395		} ,
{ 400	,	406		,	411		,	413		,	418		} ,
{ 424	,	430		,	435		,	438		,	443		} ,
{ 450	,	456		,	461		,	464		,	469		} ,
{ 476	,	483		,	489		,	491		,	497		} ,
{ 505	,	512		,	518		,	521		,	527		} ,
{ 535	,	542		,	548		,	552		,	558		} ,
{ 566	,	575		,	581		,	584		,	591		} ,
{ 600	,	609		,	616		,	619		,	627		} ,
{ 636	,	645		,	652		,	656		,	664		} ,
{ 674	,	683		,	691		,	695		,	703		} ,
{ 714	,	724		,	732		,	736		,	745		} ,
{ 756	,	767		,	776		,	780		,	789		} ,
{ 801	,	813		,	822		,	827		,	836		} ,
{ 849	,	861		,	871		,	876		,	886		} ,
{ 899	,	912		,	922		,	928		,	939		} ,
{ 952	,	966		,	977		,	983		,	995		} ,
{ 1009	,	1024	,	1035	,	1041	,	1054	} ,
{ 1069	,	1085	,	1097	,	1103	,	1116	} ,
{ 1133	,	1149	,	1162	,	1169	,	1183	} ,
{ 1200	,	1217	,	1231	,	1238	,	1253	} ,
{ 1271	,	1290	,	1304	,	1312	,	1328	} ,
{ 1347	,	1366	,	1382	,	1390	,	1407	} ,
{ 1427	,	1448	,	1464	,	1473	,	1490	} ,
{ 1512	,	1534	,	1551	,	1560	,	1579	} ,
{ 1602	,	1625	,	1644	,	1653	,	1673	} ,
{ 1697	,	1722	,	1741	,	1751	,	1772	} ,
{ 1798	,	1824	,	1845	,	1855	,	1877	} ,
{ 1905	,	1932	,	1954	,	1966	,	1989	} ,
{ 2018	,	2047	,	2071	,	2083	,	2107	} ,
{ 2138	,	2169	,	2194	,	2207	,	2233	} ,
{ 2265	,	2298	,	2324	,	2338	,	2365	} ,
{ 2400	,	2435	,	2462	,	2477	,	2506	} ,
{ 2543	,	2580	,	2609	,	2624	,	2655	} ,
{ 2694	,	2733	,	2764	,	2780	,	2813	} ,
{ 2854	,	2895	,	2928	,	2945	,	2980	} ,
{ 3024	,	3068	,	3103	,	3121	,	3158	} ,
{ 3204	,	3250	,	3287	,	3306	,	3345	} ,
{ 3394	,	3443	,	3482	,	3503	,	3544	} ,
{ 3596	,	3648	,	3690	,	3711	,	3755	} ,
{ 3810	,	3865	,	3909	,	3932	,	3978	} ,
{ 4037	,	4095	,	4141	,	4165	,	4215	} ,
{ 4277	,	4338	,	4388	,	4413	,	4465	} ,
{ 4531	,	4596	,	4649	,	4675	,	4731	} ,
{ 4800	,	4870	,	4925	,	4954	,	5012	} ,
{ 5086	,	5159	,	5218	,	5248	,	5310	} ,
{ 5388	,	5466	,	5528	,	5560	,	5626	} ,
{ 5708	,	5791	,	5857	,	5891	,	5961	} ,
{ 6048	,	6135	,	6205	,	6241	,	6315	} ,
{ 6408	,	6500	,	6574	,	6612	,	6691	} ,
{ 6789	,	6887	,	6965	,	7005	,	7088	} ,
{ 7192	,	7296	,	7379	,	7422	,	7510	} ,
{ 7620	,	7730	,	7818	,	7863	,	7956	} ,
{ 8073	,	8190	,	8283	,	8331	,	8430	} ,
{ 8553	,	8677	,	8775	,	8826	,	8931	} ,
{ 9062	,	9192	,	9297	,	9351	,	9462	} ,
{ 9600	,	9739	,	9850	,	9907	,	10025	} ,
{ 10171	,	10318	,	10436	,	10496	,	10621	} ,
{ 10776	,	10932	,	11056	,	11120	,	11252	} ,
{ 11417	,	11582	,	11714	,	11782	,	11921	} ,
{ 12096	,	12270	,	12410	,	12482	,	12630	} ,
{ 12815	,	13000	,	13148	,	13224	,	13381	} ,
{ 13577	,	13773	,	13930	,	14011	,	14177	} ,
{ 14384	,	14592	,	14758	,	14844	,	15020	} ,
{ 15240	,	15460	,	15636	,	15726	,	15913	} ,
{ 16146	,	16379	,	16566	,	16662	,	16859	} ,
{ 17106	,	17353	,	17551	,	17652	,	17862	} ,
{ 18123	,	18385	,	18594	,	18702	,	18924	} ,
{ 19201	,	19478	,	19700	,	19814	,	20049	} ,
{ 20343	,	20636	,	20871	,	20992	,	21241	} ,
{ 21552	,	21863	,	22112	,	22241	,	22504	} ,
{ 22834	,	23164	,	23427	,	23563	,	23842	} ,
{ 24192	,	24541	,	24820	,	24964	,	25260	} ,
{ 25630	,	26000	,	26296	,	26449	,	26762	} ,
{ 27154	,	27546	,	27860	,	28021	,	28354	} ,
{ 28769	,	29184	,	29517	,	29688	,	30040	} ,
{ 30480	,	30920	,	31272	,	31453	,	31826	} ,
{ 32292	,	32758	,	33131	,	33323	,	33718	} ,
{ 34212	,	34706	,	35101	,	35305	,	35723	} ,
{ 36247	,	36770	,	37188	,	37404	,	37848	} ,
{ 38402	,	38956	,	39400	,	39628	,	40098	} ,
{ 40685	,	41273	,	41743	,	41985	,	42482	}
};