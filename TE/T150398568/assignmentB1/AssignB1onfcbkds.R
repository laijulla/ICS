//creating dataset of subset
> d=read.csv2("dataset_Facebook1.csv")
> exit
Error: object 'exit' not found
> d=read.csv2("dataset_Facebook.csv")
> dim(d)
[1] 500  19
> nrow(d)
[1] 500
> ncol(d)
[1] 19

> head(d)
  Page.total.likes.Type.Category.Post.Month.Post.Weekday.Post.Hour.Paid.Lifetime.Post.Total.Reach.Lifetime.Post.Total.Impressions.Lifetime.Engaged.Users.Lifetime.Post.Consumers.Lifetime.Post.Consumptions.Lifetime.Post.Impressions.by.people.who.have.lik ...
1                                                                                                                                                                                        139441,Photo,2,12,4,3,0,2752,5091,178,109,159,3078,1640,119,4,79,17,100
2                                                                                                                                                                              139441,Status,2,12,3,10,0,10460,19057,1457,1361,1674,11710,6112,1108,5,130,29,164
3                                                                                                                                                                                         139441,Photo,3,12,3,3,0,2413,4373,177,113,154,2812,1503,132,0,66,14,80
4                                                                                                                                                                           139441,Photo,2,12,2,10,1,50128,87991,2211,790,1119,61027,32048,1386,58,1572,147,1777
5                                                                                                                                                                                     139441,Photo,2,12,2,3,0,7244,13594,671,410,580,6228,3200,396,19,325,49,393
6                                                                                                                                                                               139441,Status,2,12,1,9,0,10472,20849,1191,1073,1389,16034,7852,1016,1,152,33,186

> sub=d[c('comment','like','share')]
> head(sub)
  comment like share
1       4   79    17
2       5  130    29
3       0   66    14
4      58 1572   147
5      19  325    49
6       1  152    33

write.csv(sub,"facebook-sub.csv")

> subset1=subset(sub,comment>50)
> subset1
    comment like share
4        58 1572   147
143      60  859    90
169     144 1622   208
229      64  367    25
245     372 5172   790
289     103  469    33
380      51 1998   128
461     146 1546   181
481      56  360    99


//merging
> dataA=read.csv2("dataset_Facebook.csv")
> dim(dataA)
[1] 500  19
> dataC=read.csv2("dataset_Facebook1.csv")
> dim(dataC)
[1] 500  19
> newAC=rbind(dataA,dataC)
> dim(newAC)
[1] 1000   19

//Sorting
> x=sub[order(-d$share),]
> head(x)
    comment like share
245     372 5172   790
169     144 1622   208
461     146 1546   181
4        58 1572   147
106      42  955   139
380      51 1998   128

//melting
melt(data = sub,id.vars = "comment")
//shows data in more detail
     comment variable value
1          4     like    79
2          5     like   130
3          0     like    66
4         58     like  1572
5         19     like   325
6          1     like   152
7          3     like   249
8          0     like   325
9          0     like   161
10         3     like   113
11         0     like   233
12         0     like    88
13         0     like    90
14         5     like   137
15         2     like   577
16         4     like    86
17         2     like    40
18        15     like   678
19         4     like    54
20         0     like    34
21         3     like    66
22         0     like     0
23         0     like    16
24         0     like    72
25         3     like    99
26         0     like    88
27        10     like   412
28         0     like   100
29        36     like   523
30        18     like   143
31        33     like   107
32         1     like    27
33         2     like   155
34         4     like    98
35         2     like    56
36         6     like   172
37         0     like    96
38        16     like    76
39        11     like   227
40         1     like    44
41         7     like   216
42         6     like   187
43         7     like    26
44         7     like    29
45         0     like    47
46         4     like    57
47         4     like   174
48         6     like    18
49         0     like    77
50         1     like    12
51         1     like    48
52        24     like   285
53         9     like   202
54         4     like    64
55         4     like    66
56         2     like    65
57         2     like   164
58         0     like    40
59         3     like    76
60         4     like   139
61         8     like   101
62         8     like   144
63        10     like   179
64         4     like   219
65         2     like    60
66        19     like    77
67         0     like    48
68        20     like   697
69         0     like    53
70         7     like    84
71         7     like   146
72        17     like   449
73         3     like   226
74        14     like   172
75         2     like    99
76        20     like   411
77         0     like     0
78         4     like    85
79         0     like    56
80         2     like    29
81         2     like    86
82        18     like   370
83         5     like   190
84         2     like   101
85         2     like    99
86        10     like   140
87         2     like   130
88         3     like   270
89         3     like    30
90         2     like   107
91        13     like   331
92         0     like    78
93         9     like   301
94         2     like   111
95         2     like   124
96         5     like   153
97         3     like    51
98         1     like   115
99         7     like   310
100       12     like   328
101        0     like     0
102       26     like  1505
103        2     like    63
104        0     like    13
105        4     like    59
106       42     like   955
107        9     like   181
108       17     like   193
109        7     like   125
110        4     like   217
111        2     like    28
112        0     like    NA
113        4     like   117
114        2     like    79
115        0     like    15
116        0     like     4
117        1     like   431
118        0     like     7
119        0     like     7
120        0     like     6
121        0     like     2
122        6     like   186
123        1     like     1
124        1     like     3
125        0     like     7
126        0     like     7
127        3     like   198
128        0     like     9
129        0     like     4
130        0     like     3
131        0     like     8
132        0     like     7
133        1     like     7
134        0     like    11
135        2     like    28
136        0     like    56
137        0     like    32
138        4     like    32
139        0     like   129
140        4     like    77
141       15     like   143
142        2     like   227
143       60     like   859
144       10     like   377
145        3     like    41
146        6     like    76
147        0     like   189
148        0     like    80
149        3     like   148
150        0     like    24
151       24     like   302
152        2     like   166
153       47     like   358
154        7     like   161
155       13     like   319
156        0     like    54
157       16     like   117
158        1     like   115
159       30     like   187
160        1     like    84
161        6     like   363
162        6     like   244
163       22     like   290
164        4     like   243
165        0     like    18
166        0     like   113
167        2     like    77
168        8     like   485
169      144     like  1622
170        6     like    99
171        3     like   188
172        2     like    30
173       38     like   163
174        6     like   179
175        5     like   204
176        2     like   165
177       29     like  1047
178        2     like   234
179        7     like   250
180        4     like   154
181       20     like   150
182        4     like   102
183        1     like   226
184        6     like   345
185       11     like    68
186        0     like    62
187        5     like   223
188        0     like    61
189        1     like   104
190        3     like   146
191        2     like   102
192        9     like   766
193        0     like    63
194        3     like   113
195        6     like   442
196        9     like   278
197        2     like    64
198        1     like    52
199        0     like    30
200       33     like  1155
201        2     like   139
202        0     like    40
203        2     like    53
204        4     like   220
205        2     like   114
206        0     like    39
207        4     like   859
208        5     like   137
209        1     like    54
210        2     like    74
211        6     like    98
212        2     like   264
213        3     like    36
214        1     like    11
215        4     like   435
216        2     like   114
217        2     like    17
218       41     like    15
219        3     like    87
220       16     like   227
221        2     like    86
222        6     like   179
223        1     like    74
224       18     like   332
225        2     like    80
226        9     like    95
227        3     like   188
228        6     like   109
229       64     like   367
230        9     like   102
231        2     like   113
232        0     like    94
233        6     like    14
234        1     like    43
235        1     like    98
236        3     like    13
237       12     like   237
238        4     like   112
239        2     like   101
240       10     like   145
241        6     like   535
242        4     like   118
243        9     like   484
244       18     like   315
245      372     like  5172
246        4     like   154
247        0     like    73
248        0     like    96
249        1     like    98
250        1     like    53
251        4     like    71
252        6     like   194
253        6     like   226
254       11     like   238
255       10     like   755
256       30     like    47
257        2     like   126
258        4     like   104
259       10     like   167
260        9     like   152
261        0     like   128
262       13     like   234
263        2     like    61
264        0     like    66
265        7     like   529
266        3     like    42
267        2     like    75
268       13     like    61
269       26     like   162
270        2     like    47
271        6     like   696
272        7     like   215
273       22     like   534
274        1     like   143
275       18     like    46
276       36     like    98
277        0     like    25
278       23     like   204
279       11     like   202
280        7     like   148
281        1     like    40
282        1     like    71
283        0     like   104
284        1     like    34
285       11     like   129
286        4     like    72
287        0     like    15
288       14     like   102
289      103     like   469
290        5     like    57
291        0     like    23
292        5     like   141
293        0     like    19
294        1     like    71
295        0     like    72
296        5     like    54
297        5     like    93
298        0     like    62
299        0     like    78
300        0     like    14
301       11     like   231
302        1     like    72
303        9     like   197
304        4     like   330
305        0     like   148
306        2     like   208
307       12     like   148
308        4     like   154
309        3     like   142
310        8     like   107
311        0     like    22
312        2     like    84
313        2     like    59
314        3     like    65
315        0     like    24
316        9     like   186
317        0     like    58
318        2     like    74
319        2     like   180
320       18     like   168
321        0     like    36
322        2     like    51
323        2     like    67
324       20     like  1372
325        2     like    57
326        2     like    33
327        1     like    79
328        3     like    97
329       16     like   617
330        7     like   139
331       20     like   199
332        1     like   107
333        0     like    50
 [ reached getOption("max.print") -- omitted 667 rows ]
//casting
> sub=d[c('Post.Month','Post.Hour','Paid')]
/*d=original dataset
c=combine*/
> head(sub)
  Post.Month Post.Hour Paid
1         12         3    0
2         12        10    0
3         12         3    0
4         12        10    1
5         12         3    0
6         12         9    0
> cast(sub,Post.Hour ~ Post.Month,mean,value = 'Paid')
   Post.Hour    1         2         3         4         5         6
1          1  NaN       NaN       NaN       NaN 0.0000000       NaN
2          2 0.00 1.0000000 1.0000000 0.5000000 0.0000000 0.3333333
3          3 0.50 0.3333333 0.0000000 0.4000000 0.3333333 0.3333333
4          4   NA 0.5000000 0.5000000 0.5000000 0.5000000 0.2000000
5          5  NaN       NaN 0.5000000 0.5000000 0.0000000 1.0000000
6          6  NaN 0.0000000 0.0000000 0.5000000 0.0000000       NaN
7          7 0.00       NaN 0.0000000 0.7500000 0.0000000 0.0000000
8          8 0.00       NaN       NaN 0.0000000 0.5000000       NaN
9          9  NaN 1.0000000 0.0000000 0.3333333 0.3333333 0.5000000
10        10 0.25       NaN 0.2000000 0.0000000 0.5000000 0.0000000
11        11 0.00       NaN       NaN       NaN 0.0000000 0.1666667
12        12 0.00 0.0000000 0.0000000 1.0000000 0.0000000 0.1666667
13        13 0.00 0.3333333 0.6666667 0.3076923 0.5000000 0.1250000
14        14  NaN       NaN 0.6666667 0.2500000 0.0000000 0.0000000
15        15  NaN       NaN 0.0000000 1.0000000       NaN       NaN
16        16 1.00       NaN       NaN       NaN       NaN       NaN
17        17  NaN       NaN 0.0000000       NaN       NaN       NaN
18        18  NaN       NaN 0.0000000       NaN       NaN       NaN
19        19  NaN       NaN 0.0000000       NaN       NaN       NaN
20        20  NaN       NaN       NaN 0.0000000       NaN       NaN
21        22  NaN       NaN       NaN       NaN       NaN 1.0000000
22        23  NaN       NaN       NaN       NaN       NaN       NaN
           7         8         9        10        11        12
1  0.0000000 0.0000000       NaN 0.0000000       NaN       NaN
2  0.0000000 1.0000000 0.5000000 0.5000000 0.6666667 0.0000000
3  0.1111111 0.4285714 0.5714286 0.3000000 0.3125000 0.2000000
4  0.5000000 0.0000000 0.5000000 0.1428571 0.0000000       NaN
5  0.5000000       NaN       NaN 0.0000000       NaN 1.0000000
6  0.6000000 0.0000000 0.0000000 0.0000000       NaN       NaN
7  1.0000000 0.0000000 0.0000000 0.0000000       NaN       NaN
8  0.5000000 0.0000000       NaN 0.0000000       NaN       NaN
9  1.0000000 0.5000000 0.0000000 0.1666667 0.2000000 0.2500000
10 0.4000000 0.2727273 0.1538462 0.2307692 0.3333333 0.1538462
11 0.5714286 1.0000000 0.0000000 0.2857143 0.2857143 0.1250000
12 0.5000000 0.3333333       NaN 0.3333333 0.0000000 1.0000000
13 0.2500000 0.0000000       NaN 0.0000000       NaN       NaN
14 0.0000000       NaN       NaN       NaN       NaN       NaN
15       NaN       NaN       NaN       NaN       NaN       NaN
16       NaN       NaN       NaN       NaN       NaN       NaN
17       NaN       NaN       NaN       NaN       NaN       NaN
18       NaN       NaN       NaN       NaN       NaN       NaN
19       NaN       NaN       NaN       NaN       NaN       NaN
20       NaN       NaN       NaN       NaN       NaN       NaN
21       NaN       NaN       NaN       NaN       NaN       NaN
22 0.0000000       NaN       NaN       NaN       NaN       NaN

