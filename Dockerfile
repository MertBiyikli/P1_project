# Use an official GCC image from Docker Hub
FROM gcc:10.3

# Install necessary packages
RUN apt-get update && apt-get install -y cmake libsqlite3-dev

# Set the working directory
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . .

# Build the application
RUN cmake . && make

# Expose the port the service runs on
EXPOSE 8080

# Run the application
CMD ["./graph_service"]
