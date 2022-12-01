Práctica 4 Algoritmos Ingeniería Informática 2020/2021

Autor:
(QUITAR LOS DEMAS NOMBRES)
-Diego Saavedra
-Nicolás Vázquez
-Pedro Peón


En este informe queda reflejado la complejidad computacional de un algoritmo
de ordenación rápida con pivote aleatorio para vectores de n elementos 
ordenados inicialmente de manera ascendente, descendente y aleatoria con un
umbral de 1, 10 y 100 elementos, para finalmente recurrir al algoritmo de
ordenacion por insercion salvo cuando es 1.
En las tablas quedan represantados el umbral usado, el tamaño de los vectores
y los tiempos de ejecución, asi como las cotas ajustada, subestimada y 
sobreestimada.
(CAMBIAR POR VUESTROS PCs)
Estos cálculos se han realizado en un hp pavilion notebook con un procesador 
Intel corei7-6700HQ, CPU con 2.6 GHz y con una Memoria Ram de 15.6Gb DDR4.

Todos los tiempos indicados en las tablas estan en microsengundos.

Todas las tablas han sido ejecutadas 3 veces por cada umbral y con doce filas 
(salvo cuando el tiempo de ejecución supere los 1000000 microsegundos) para
mayor precisión y con el objetivo de evitar el mayor número de valores
anómalos.

* Estes tiempos son inferiores a 500 microsegundos por lo que entraron en un 
bucle de 2000 interacciones y se calculó su tiempo medio.
** Valores anómalos.

--------------------------------------------------------------------------------

UMBRAL 1:
Cotas en el algoritmo de ordenación rápida con una inicialización ascendente:
    f(n)=n              (cota subestimada)
    g(n)=n^1.07         (cota ajustada)
    h(n)=n^1.15         (cota sobreestimada)

Inicializacion ascendente
            n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*         500         23.981      0.0479620      0.0310434      0.0188822
*        1000         48.627      0.0486275      0.0299835      0.0172537
*        2000        102.447      0.0512232      0.0300881      0.0163800
*        4000        221.942      0.0554855      0.0310481      0.0159908
         8000        550.000      0.0607500      0.0366485**    0.0178570**
        16000       1003.000      0.0626875      0.0318341      0.0146745
        32000       2154.000      0.0673125      0.0325638      0.0142011
        64000       4457.000      0.0696406      0.0320945      0.0138415
       128000      10322.000      0.0806406      0.0334037      0.0132189
       256000      20494.000      0.0810547      0.0334819      0.0123638
       512000      41834.000      0.0817070      0.0325545      0.0113728
      1024000      84151.000      0.0821787      0.0311916      0.0103089

La constante a la que tiende T(n)/g(n) es: 0.032



Cotas en el algoritmo de ordenación rápida con una inicialización descendente:
    f(n)=n              (cota subestimada)
    g(n)=n^1.08         (cota ajustada)
    h(n)=n^1.19         (cota sobreestimada)

Inicializacion descendente
            n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*         500         26.007      0.0500140      0.0316375      0.0159704
*        1000         51.239      0.0512385      0.0294847      0.0137910
*        2000        109.089      0.0545443      0.0296939      0.0128693
*        4000        223.684      0.0559210      0.0288012      0.0115660
*        8000        468.608      0.0585760      0.0285412      0.0106202
        16000        968.000      0.0605000      0.0278885      0.0096155
        32000       2049.000      0.0640312      0.0279242      0.0089210
        64000       4315.000      0.0674219      0.0278168      0.0082343
       128000      10475.000      0.0818359**    0.0319424**    0.0087614**
       256000      19627.000      0.0766680      0.0283110      0.0071953
       512000      41282.000      0.0806289      0.0281676      0.0066333
      1024000      85765.000      0.0837549      0.0276813      0.0060402

La constante a la que tiende T(n)/g(n) es: 0.028



Cotas en el algoritmo de ordenación rápida con una inicialización aleatoria:
    f(n)=n              (cota subestimada)
    g(n)=n^1.1          (cota ajustada)
    h(n)=n^1.3          (cota sobreestimada)

Inicializacion aleatoria
            n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*         500         45.433      0.0908650      0.0478090      0.0140833
*        1000         91.244      0.0912440      0.0457303      0.0114869
*        2000        204.357      0.1021787      0.0467813      0.0104484
*        4000        428.739      0.1071847      0.0467657      0.0089026
         8000        890.000      0.1112500      0.0452888      0.0075054
        16000       1917.000      0.1198125      0.0455082      0.0065655
        32000       3966.000      0.1239375      0.0439226      0.0055164
        64000       8676.000      0.1355625      0.0448251      0.0049010
       128000      19458.000      0.1520156      0.0458994      0.0044640
       256000      41752.000      0.1630938      0.0459476      0.0038901
       512000      87124.000      0.1701641      0.0457026      0.0032968
      1024000     179842.000      0.1756270      0.0440110      0.0027638

La constante a la que tiende T(n)/g(n) es: 0.045

--------------------------------------------------------------------------------

UMBRAL 10:
Cotas en el algoritmo de ordenación rápida con una inicialización ascendente:
    f(n)=n^1.04         (cota subestimada)
    g(n)=n^1.1          (cota ajustada)
    h(n)=n^1.18         (cota sobreestimada)

Inicializacion ascendente
            n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*         500         15.160      0.0236467      0.0162867      0.0099064
*        1000         33.404      0.0253399      0.0167419      0.0096340
*        2000         69.801      0.0257508      0.0163203      0.0088848
*        4000        157.886      0.0283270      0.0172218      0.0088698
*        8000        333.394      0.0290900      0.0169652      0.0082663
        16000        733.000      0.0311042      0.0174009      0.0080213
        32000       1620.000      0.0334317      0.0179411      0.0078242
        64000       3146.000      0.0315741**    0.0162540      0.0067060
       128000       7346.000      0.0358552      0.0177060      0.0066110
       256000      15605.000      0.0360420      0.0175469      0.0064795
       512000      31613.000      0.0364943      0.0165832      0.0057933
      1024000      65154.000      0.0365788      0.0159445      0.0052697

La constante a la que tiende T(n)/g(n) es: 0.016



Cotas en el algoritmo de ordenación rápida con una inicialización descendente:
    f(n)=n              (cota subestimada)
    g(n)=n^1.1          (cota ajustada)
    h(n)=n^1.2          (cota sobreestimada)

Inicializacion descendente
            n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*         500         17.273      0.0345460      0.0185567      0.0099679
*        1000         36.450      0.0364500      0.0182683      0.0091558
*        2000         76.978      0.0384888      0.0179983      0.0084164
*        4000        163.860      0.0409650      0.0178734      0.0077983
*        8000        358.258      0.0447822      0.0182304      0.0074214
        16000        803.000      0.0501875      0.0180627      0.0072406
        32000       1897.000      0.0542813      0.0210089**    0.0074454**
        64000       3505.000      0.0597656      0.0181088      0.0059879
       128000       7682.000      0.0600156      0.0185158      0.0057124
       256000      16727.000      0.0653398      0.0188085      0.0054141
       512000      34264.000      0.0669219      0.0179738      0.0048274
      1024000      73656.000      0.0719297      0.0180251      0.0045170

La constante a la que tiende T(n)/g(n) es: 0.018



Cotas en el algoritmo de ordenación rápida con una inicialización aleatoria:
    f(n)=n              (cota subestimada)
    g(n)=n^1.1          (cota ajustada)
    h(n)=n^1.2          (cota sobreestimada)

Inicializacion aleatoria
            n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*         500         39.011      0.0780220      0.0419102      0.0225125
*        1000         81.153      0.0811535      0.0406731      0.0203848
*        2000        166.417      0.0832087      0.0389104      0.0181955
*        4000        377.743      0.0944359      0.0412032      0.0179773
         8000        781.000      0.0976250      0.0397422      0.0166787
        16000       1850.000      0.1156250      0.0439177**    0.0161812
        32000       3512.000      0.1197500      0.0388946      0.0137840
        64000       8076.000      0.1261875      0.0417252      0.0137769
       128000      17471.000      0.1364922      0.0421102      0.0129917
       256000      35456.000      0.1385000      0.0398681      0.0114763
       512000      73437.000      0.1434316      0.0385228      0.0103464
      1024000     160033.000      0.1562822      0.0391633      0.0098141

La constante a la que tiende T(n)/g(n) es: 0.039

--------------------------------------------------------------------------------

UMBRAL 100:
Cotas en el algoritmo de ordenación rápida con una inicialización ascendente:
    f(n)=n^1.04         (cota subestimada)
    g(n)=n^1.1          (cota ajustada)
    h(n)=n^1.18         (cota sobreestimada)
    
Inicializacion ascendente
            n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*         500         16.212      0.0252868      0.0174163      0.0105935
*        1000         34.181      0.0259293      0.0171313      0.0098581
*        2000         73.331      0.0270529      0.0171456      0.0093340
*        4000        165.513      0.0296954      0.0180537      0.0092983
*        8000        346.338      0.0302195      0.0176239      0.0085872
        16000        791.000      0.0335654      0.0187778      0.0084560
        32000       2040.000      0.0420992**    0.0225925**    0.0098527**
        64000       3337.000      0.0336911      0.0172408      0.0071132
       128000       7310.000      0.0356795      0.0176192      0.0068772
       256000      15597.000      0.0370230      0.0175379      0.0064762
       512000      32509.000      0.0375286      0.0170532      0.0059575
      1024000      66520.000      0.0377457      0.0172788      0.0053802

La constante a la que tiende T(n)/g(n) es: 0.017



Cotas en el algoritmo de ordenación rápida con una inicialización descendente:
    f(n)=n              (cota subestimada)
    g(n)=n^1.1          (cota ajustada)
    h(n)=n^1.2          (cota sobreestimada)

Inicializacion descendente
            n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*         500         17.764      0.0355280      0.0190842      0.0102512
*        1000         37.191      0.0371905      0.0186394      0.0093418
*        2000         80.406      0.0402030      0.0187999      0.0087913
*        4000        164.944      0.0412360      0.0179916      0.0078499
*        8000        347.424      0.0434281      0.0176792      0.0071970
        16000        839.000      0.0524375**    0.0199173**    0.0075652**
        32000       1546.000      0.0483125      0.0171216      0.0060678
        64000       3267.000      0.0510469      0.0168792      0.0055813
       128000       7337.000      0.0573203      0.0176843      0.0054559
       256000      16141.000      0.0630508      0.0181496      0.0052245
       512000      32969.000      0.0643926      0.0172945      0.0046450
      1024000      71931.000      0.0702451      0.0176030      0.0044112

La constante a la que tiende T(n)/g(n) es: 0.017



Cotas en el algoritmo de ordenación rápida con una inicialización aleatoria:
    f(n)=n              (cota subestimada)
    g(n)=n^1.1          (cota ajustada)
    h(n)=n^1.2          (cota sobreestimada)

Inicializacion aleatoria
            n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*         500         34.540      0.0690810      0.0371075      0.0199326
*        1000         75.141      0.0751410      0.0376597      0.0188746
*        2000        174.144      0.0870722      0.0407171      0.0180403
*        4000        373.387      0.0933469      0.0407281      0.0177700
         8000        784.000      0.0960000      0.0398949      0.0162408
        16000       1559.000      0.0974375      0.0370096      0.0140573
        32000       3535.000      0.1104688      0.0391493      0.0138742
        64000       8426.000      0.1316563      0.0435335**    0.0143948**
       128000      17266.000      0.1348906      0.0416160      0.0128393
       256000      35531.000      0.1387930      0.0399525      0.0115006
       512000      77910.000      0.1521680      0.0398692      0.0109766
      1024000     157667.000      0.1539717      0.0395843      0.0096690

La constante a la que tiende T(n)/g(n) es: 0.039

--------------------------------------------------------------------------------
Al ordenar n elementos ya ordenados ascendientemente con un umbral de 10, se
puede apreciar como sus tiempos son notablemente mejores que con umbral 1 y 100
con las mismas condiciones, lo cual tiene explicacion comparandolo con umbral
1 porque se ahorran muchas iteraciones de ordenacion rapida con complejidad
teorica n*log(n) al ser finalmente ordenado con insercion, que su complejidad
es inferior en este caso siendo solo de (n). Pero que umbral de 10 sea mas
rapido que con 100 es inexplicable ya que aplicando el mismo razonamiento que
con umbral 1 debería ser mas rapido con umbral 100, ya que participa mas tiempo
el algoritmo de insercion que mas es eficiente con elementos ordenados 
ascendientemente como dije antes.
Tambien al ordenar cantidades de n elementos no muy grandes, ya ordenados
descendientemente con un umbral de 10, conseguimos mejores tiempos que en los
otros dos umbrales, debido a que en este caso el algoritmo de insercion es
muy ineficiente con complejidad cuadratica y cuanto mas ordenados se le dejen
los elementos con ordenacion rapida a insercion, mas rapido se executara. Pero
esto no se cumple con umbral 1, con lo que suponemos que insercion es mas
eficiente que llegar hasta el caso base de ordenacion rapida, a pesar de su
menor complejidad teorica en este caso.
En cambio al ordenar n elementos aleatorios con un umbral de 100, tiene
mayormente mejores tiempos que en el mismo caso con los otros dos umbrales,
teoricamente no deberia ser asi ya que estamos en el caso medio del algoritmo
de insercion con complejidad cuadratica y convedria usarlo lo menos posible,
ya que el caso medio de ordenacion rapida es inferior (n*log(n)), con lo que
deducimos que la complejidad empirica en el caso medio de insercion es inferior.
