v 20130925 2
C 40000 40000 0 0 0 title-B.sym
C 43400 44900 1 0 0 ATmega8-1.sym
{
T 43500 49700 5 10 0 0 0 0 1
footprint=DIP28N
T 45700 49500 5 10 1 1 0 6 1
refdes=U1
T 43500 50500 5 10 0 0 0 0 1
device=ATmega8
}
N 46000 48000 47500 48000 4
N 47500 48000 47500 48700 4
N 46000 47800 47800 47800 4
N 47800 47800 47800 48700 4
N 46000 47600 48100 47600 4
N 48100 47600 48100 48700 4
N 46000 47400 48400 47400 4
N 48400 47400 48400 48700 4
C 42000 45200 1 0 0 crystal-1.sym
{
T 42200 45700 5 10 0 0 0 0 1
device=CRYSTAL
T 42200 45500 5 10 1 1 0 0 1
refdes=U2
T 42200 45900 5 10 0 0 0 0 1
symversion=0.1
T 42000 45200 5 10 0 0 0 0 1
footprint=HC49
}
N 42700 45300 43400 45300 4
N 42000 44900 42000 45300 4
N 42000 45100 43400 45100 4
C 42200 44000 1 90 0 capacitor-1.sym
{
T 41500 44200 5 10 0 0 90 0 1
device=CAPACITOR
T 41700 44200 5 10 1 1 90 0 1
refdes=C1
T 41300 44200 5 10 0 0 90 0 1
symversion=0.1
T 42200 44000 5 10 0 0 0 0 1
footprint=ACY200
}
C 42900 44000 1 90 0 capacitor-1.sym
{
T 42200 44200 5 10 0 0 90 0 1
device=CAPACITOR
T 42400 44200 5 10 1 1 90 0 1
refdes=C2
T 42000 44200 5 10 0 0 90 0 1
symversion=0.1
T 42900 44000 5 10 0 0 0 0 1
footprint=ACY200
}
N 42700 44900 42700 45300 4
C 41900 43700 1 0 0 gnd-1.sym
C 42600 43700 1 0 0 gnd-1.sym
C 40900 48200 1 270 0 connector5-1.sym
{
T 42400 46400 5 10 0 0 270 0 1
device=CONNECTOR_5
T 42600 48100 5 10 1 1 270 0 1
refdes=CONN1
T 40900 48200 5 10 0 0 0 0 1
footprint=SIL 5
}
N 43400 45700 41700 45700 4
N 41700 45700 41700 46500 4
N 41100 46500 41100 43500 4
N 41100 43500 46900 43500 4
N 46900 43500 46900 47000 4
N 46900 47000 46000 47000 4
C 48300 46400 1 0 0 vcc-1.sym
C 49300 46400 1 0 0 vcc-1.sym
C 48400 45200 1 0 0 gnd-1.sym
C 49400 45200 1 0 0 gnd-1.sym
C 49300 46400 1 270 0 capacitor-4.sym
{
T 50400 46200 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 49800 46200 5 10 1 1 270 0 1
refdes=C3
T 50000 46200 5 10 0 0 270 0 1
symversion=0.1
T 49300 46400 5 10 0 0 0 0 1
footprint=RADIAL_CAN 200
}
C 48700 45500 1 90 0 capacitor-1.sym
{
T 48000 45700 5 10 0 0 90 0 1
device=CAPACITOR
T 48200 45700 5 10 1 1 90 0 1
refdes=C4
T 47800 45700 5 10 0 0 90 0 1
symversion=0.1
T 48700 45500 5 10 0 0 0 0 1
footprint=ACY300
T 48700 45500 5 10 1 0 0 0 1
value=0.1uF
}
C 51400 46300 1 0 0 max1674-1.sym
{
T 53600 49200 5 10 1 1 0 6 1
refdes=U3
T 51700 49550 5 10 0 0 0 0 1
device=MAX1674
T 51700 49750 5 10 0 0 0 0 1
footprint=usop-8
}
C 42200 46200 1 0 0 gnd-1.sym
C 47300 50400 1 270 0 connector8-1.sym
{
T 50500 50300 5 10 0 0 270 0 1
device=CONNECTOR_8
T 49900 50300 5 10 1 1 270 0 1
refdes=CONN2
T 47300 50400 5 10 0 0 0 0 1
footprint=CONNECTOR 8 1
}
N 46000 47200 48700 47200 4
N 48700 47200 48700 48700 4
C 49500 48400 1 0 0 gnd-1.sym
C 49200 48700 1 180 0 vcc-1.sym
C 53800 47000 1 0 0 gnd-1.sym
C 53700 47900 1 0 0 vcc-1.sym
C 52800 46000 1 0 0 gnd-1.sym
C 51400 47700 1 90 0 vcc-1.sym
C 51600 46100 1 90 0 capacitor-1.sym
{
T 50900 46300 5 10 0 0 90 0 1
device=CAPACITOR
T 51100 46300 5 10 1 1 90 0 1
refdes=C5
T 50700 46300 5 10 0 0 90 0 1
symversion=0.1
T 51600 46100 5 10 0 0 0 0 1
footprint=ACY300
T 51600 46100 5 10 1 0 0 0 1
value=0.1uF
}
C 51300 45800 1 0 0 gnd-1.sym
C 53900 48300 1 0 0 inductor-1.sym
{
T 54100 48800 5 10 0 0 0 0 1
device=INDUCTOR
T 54100 48600 5 10 1 1 0 0 1
refdes=L1
T 54100 49000 5 10 0 0 0 0 1
symversion=0.1
T 53900 48300 5 10 0 0 0 0 1
footprint=ACY300
}
C 55000 47500 1 90 0 capacitor-1.sym
{
T 54300 47700 5 10 0 0 90 0 1
device=CAPACITOR
T 54500 47700 5 10 1 1 90 0 1
refdes=C6
T 54100 47700 5 10 0 0 90 0 1
symversion=0.1
T 55000 47500 5 10 0 0 0 0 1
footprint=ACY300
T 55000 47500 5 10 1 0 0 0 1
value=0.1uF
}
C 55400 48400 1 270 0 capacitor-4.sym
{
T 56500 48200 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 55900 48200 5 10 1 1 270 0 1
refdes=C7
T 56100 48200 5 10 0 0 270 0 1
symversion=0.1
T 55400 48400 5 10 0 0 0 0 1
footprint=RADIAL_CAN 200
}
N 55600 48400 54800 48400 4
C 54700 47200 1 0 0 gnd-1.sym
C 55500 47200 1 0 0 gnd-1.sym
C 57300 48900 1 180 0 connector2-1.sym
{
T 57100 47900 5 10 0 0 180 0 1
device=CONNECTOR_2
T 57300 48100 5 10 1 1 180 0 1
refdes=CONN3
T 57300 48900 5 10 0 0 0 0 1
footprint=CONNECTOR 1 2
}
C 55700 49000 1 180 0 gnd-1.sym
N 42000 46500 42000 45500 4
N 42000 45500 43400 45500 4
N 41400 46500 41400 45900 4
N 41400 45900 43400 45900 4
C 53400 42900 1 0 0 dht22.sym
{
T 55200 45100 5 10 1 1 0 6 1
refdes=U4
T 53800 45300 5 10 0 0 0 0 1
device=DHT22
T 53800 45500 5 10 0 0 0 0 1
footprint=SIL 4
}
C 52400 44700 1 0 0 vcc-1.sym
C 52800 43800 1 90 0 capacitor-1.sym
{
T 52100 44000 5 10 0 0 90 0 1
device=CAPACITOR
T 52300 44000 5 10 1 1 90 0 1
refdes=C8
T 51900 44000 5 10 0 0 90 0 1
symversion=0.1
T 52800 43800 5 10 0 0 0 0 1
footprint=ACY200
}
N 52600 44700 53500 44700 4
N 53500 44700 53500 44600 4
C 52500 43500 1 0 0 gnd-1.sym
C 53400 43100 1 0 0 gnd-1.sym
C 53400 43500 1 0 0 gnd-1.sym
N 53500 44200 53000 44200 4
N 53000 44200 53000 42400 4
C 50400 42400 1 90 0 resistor-1.sym
{
T 50000 42700 5 10 0 0 90 0 1
device=RESISTOR
T 50100 42600 5 10 1 1 90 0 1
refdes=R1
T 50400 42400 5 10 0 0 0 0 1
footprint=ACY300
}
C 50100 43300 1 0 0 vcc-1.sym
N 43400 46500 42900 46500 4
N 42900 42300 42900 46500 4
N 43000 42300 42900 42300 4
N 42900 42400 53000 42400 4