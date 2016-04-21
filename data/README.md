Sum of distance: 318.511
The waste of time:49.344069s
1e-25 0.99999 result_tmp/Simulated_Path_3_2.txt

```
awk -F':' '{
if($0~/1e-25/){
	split($0,A," ");
	plan=A[2];
}
else{
	if($1~/Sum of distance/){
		distance=$2;
	}
	else{if($1~/The waste of time/){
		time=$2;
		print plan"\t"distance"\t"time;
	}}>
}
}' nohup.out
```

```{R}
mydata=read.table("result_tmp_2/result.txt",header = T,sep="\t");
library(sm)
mydata.factor=factor(mydata[,1],labels=c("Annealing plan 0.999","Annealing plan 0.9999","Annealing plan 0.99999","Annealing plan 0.999999"));
sm.density.compare(mydata[,2],mydata.factor,xlab="Solution of a TSP")
title(main="Simulated Annealing on Different Annealing Plan")
colfill=c(2:(1+length(levels(mydata.factor))))
legend("topright",inset=.01,levels(mydata.factor),fill=colfill)

boxplot(mydata[,3]~mydata[,1],data=mydata,main="Simulated Annealing on Different Annealing Plan",xlab="Annealing plan",ylab="Time wasted(s)")

mydata=read.table("result_tmp_2/result.txt",header = T,sep="\t");
library(sm)
mydata.factor=factor(mydata[,1],labels=c("r 0.999","r 0.9999","r 0.99999","r 0.999999"));
sm.density.compare(mydata[,2],mydata.factor,xlab="Solution of a TSP")
colfill=c(2:(1+length(levels(mydata.factor))))
legend("topright",inset=.01,levels(mydata.factor),fill=colfill)

boxplot(mydata[,3]~mydata[,1],data=mydata,xlab="Annealing plan",ylab="Time wasted(s)")
```


```{octave}
cities=load('TSPdata.txt');
xx=cities(order,1);
yy=cities(order,2);
plot(xx,yy,'-*')
title('TSP route(p=0.999999,distance=362.57)')
print('TSP_route_362.png','-dpng')

xx=cities(order,1);
yy=cities(order,2);
plot(xx,yy,'-*')
title('TSP route(p=0.999,distance=377.771)')
print('TSP_route_377.png','-dpng')


xx=cities(order,1);
yy=cities(order,2);
plot(xx,yy,'-*')
title('TSP route(p=0.9999,distance=372.949)')
print('TSP_route_372.png','-dpng')

xx=cities(order,1);
yy=cities(order,2);
plot(xx,yy,'-*')
title('TSP route(p=0.99999,distance=363.964)')
print('TSP_route_363.png','-dpng')
```
