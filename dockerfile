# FROM ubuntu:latest

# # Install the necessary dependencies
# RUN apt-get update && apt-get install -y cmake g++ git curl unzip

# # Copy the project files into the image
# COPY . /app
# RUN curl https://pocoproject.org/releases/poco-1.13.3/poco-1.13.3.zip -o poco.zip &&\
#     unzip poco.zip &&\
#     cd poco-1.13.3 &&\
#     mkdir cmake-build &&\
#     cd cmake-build &&\
#     cmake .. &&\
#     cmake --build . --target install


# # Build the project
# WORKDIR /app
# RUN cmake . && make

# # Expose the application port
# EXPOSE 8080

# # Start the application
# CMD ["/app/serve"]


FROM ubuntu:latest AS builder

# Install build dependencies
RUN apt-get update && apt-get install -y cmake g++ git curl unzip

# Download and build Poco library
WORKDIR /tmp
RUN curl https://pocoproject.org/releases/poco-1.13.3/poco-1.13.3.zip -o poco.zip &&\
    unzip poco.zip &&\
    cd poco-1.13.3 &&\
    mkdir cmake-build &&\
    cd cmake-build &&\
    cmake .. &&\
    cmake --build . --target install

COPY . /app
WORKDIR /app
RUN cmake . && make
# Clean up temporary files
RUN rm -rf /tmp/*

FROM ubuntu:latest

# Copy project files and Poco libraries
COPY --from=builder /app /app
COPY --from=builder /usr/local/ /usr/local/

WORKDIR /app
# Expose application port
EXPOSE 8080

# Start the application
CMD ["/app/serve"]