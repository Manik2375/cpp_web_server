DOCKER_IMAGE =  cpp_web_server
DOCKER_TAG = latest

build:
	docker build -t $(DOCKER_IMAGE):$(DOCKER_TAG) .

run:
	docker run -p 4005:4005 -v $(PWD)/assets:/app/assets $(DOCKER_IMAGE):$(DOCKER_TAG)

.PHONY: build run