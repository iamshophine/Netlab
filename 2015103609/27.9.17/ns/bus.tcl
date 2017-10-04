set ns [new Simulator]
set nt [open out.nam w]

$ns namtrace-all $nt
proc finish {} {
	global ns nt
		$ns flush-trace
		close $nt
		exec nam out.nam &
		exit 0
}
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

set lan0 [$ns newLan "$n0 $n1 $n2 $n3 $n4 $n5" 0.5Mb 40ms LL Queue/DropTail MAC/Csma/Cd Chanel]

set tcp0 [new Agent/TCP]

$ns attach-agent $n1 $tcp0
$tcp0 set class-1
set sink0 [new Agent/TCPSink]
$ns attach-agent $n3 $sink0
$ns connect $tcp0 $sink0
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.01
$cbr0 attach-agent $tcp0
$ns at 0.5 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 50.0 "finish"
$ns run
