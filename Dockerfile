# Use an official GCC image from Docker Hub
FROM gcc:latest

# Install necessary packages
RUN apt-get update && apt-get install -y cmake libsqlite3-dev

# Set the working directory
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . .

# Build the application
RUN cmake . && make

# Verify that the application binary exists and has correct permissions
RUN ls -l /app/graph_service

# Expose the port the service runs on
EXPOSE 8080

# Run the application
CMD ["./graph_service"]
