mydata<-read.csv("data.csv")

#subsetting
subset2<-subset(mydata,X>=2000 & X<=3000 ,select=c(reviewerID,asin,reviewerName,overall))
head(subset2)
tail(subset2)
subset1<-subset(mydata,X>=4000 & X<=5000 ,select=c(reviewerID,asin,reviewerName,overall))
head(subset1)
tail(subset1)

#merging
mer=merge(x = subset1, y = subset2, by = "reviewerID", all = TRUE)
head(mer)
tail(mer)

#sorting
sortsubset1<-subset1[order(subset1$overall),]
head(sortsubset1)
tail(sortsubset1)


sortsubset3<-subset1[order(subset1$"reviewerName"),]
head(sortsubset3)
tail(sortsubset3)

sortsubset4<-subset2[order(subset2$"reviewerName"),]
head(sortsubset4)
tail(sortsubset4)

#transposing
transdata1<-t(subset1)
head(transdata1)
tail(transdata1)

transdata1<-t(subset2)
head(transdata1)
tail(transdata1)

#melting
library(MASS)

meltdata <- melt(mydata, id = c("reviewerID","asin"))
head(meltdata)
tail(meltdata)

#casting
castdata <- cast(meltdata, reviewerID+asin~variable,)
head(castdata)
tail(castdata)