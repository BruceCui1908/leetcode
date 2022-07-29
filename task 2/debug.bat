docker rm -f task-2
docker rmi task:2

docker build -t task:2 .
docker run -id --name task-2 task:2
docker exec -it task-2 /bin/bash