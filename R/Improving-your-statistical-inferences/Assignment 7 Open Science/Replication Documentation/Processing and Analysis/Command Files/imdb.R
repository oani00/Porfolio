
#import the data
setwd("F:/Dropbox/Textos/projeto curso/Replication Documentation/Processing and Analysis/Importable Data/imdb")

#make a dataframe of the entire set
imdb <- read.csv(file="tmdb_5000_movies.csv",head=TRUE,sep=",")

#check if all is ok
names(imdb)

#check the release dates
plot(imdb$release_date)

#make a subset with the variables of interest
deinteresse <- imdb[,13:14]

#set the seed
set.seed(666)

#select 1331 movies at random (seed 666)
#call them "selecionados"
selecionados <- deinteresse[sample(nrow(deinteresse), 1331), ]

#check if all is ok
str(selecionados)

#Run the spearman correlation test
cor.test(selecionados$runtime, selecionados$revenue, method = "pearson")

#Plot a simple linear regression line to better visualize the correlation

linear <- lm(selecionados$runtime ~ selecionados$revenue)
plot(selecionados$runtime, selecionados$revenue,
     main = "Linear fit of 1331 movies", 
  	    xlab = "Screentime in minutes",
  	    ylab = "Revenue in $")
abline(linear, col="red")
