#  ┌───┐
#  │┌─┐│      /
#  ││ │├──┬─┐┌┐
#  ││ ││┌┐│┌┐┼┤
#  │└─┘│┌┐│││││
#  └───┴┘└┴┘└┴┘

#https://stackoverflow.com/questions/5651654/ffmpeg-how-to-split-video-efficiently

echo "Usage : ffsplit.sh input.file time"

#file="$1"
#time="$2"

ffmpeg -i $1 -vcodec copy -acodec copy -ss 00:00:00 -t $2 parte1.mkv -vcodec copy -acodec copy -ss $2 parte2.mkv