# Use a base image
FROM debian:buster-slim

# Install required dependencies
RUN apt-get update && \
    apt-get install -y wget bzip2 g++ cmake && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Download and install Miniconda
RUN wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -O miniconda.sh && \
    bash miniconda.sh -b -p /opt/conda && \
    rm miniconda.sh

# Add Miniconda to the PATH
ENV PATH="/opt/conda/bin:$PATH"
ENV CONDA_DEFAULT_ENV=myenv
ENV CONDA_PREFIX=/opt/conda/envs/$CONDA_DEFAULT_ENV

# Update Conda and create a Conda environment
RUN conda update -n base -c defaults conda && \
    conda create -n myenv python=3.8 && \
    echo "conda activate myenv" >> ~/.bashrc

# Install xeus-cling C++ kernel
RUN conda install -n myenv -c conda-forge xeus-cling

# Install Jupyter Notebook
RUN conda install -n myenv -c conda-forge notebook

# Create a directory for Jupyter Notebook files
RUN mkdir /notebooks

# Expose the Jupyter Notebook port
EXPOSE 8888

# Start Jupyter Notebook with xeus-cling
CMD ["jupyter", "notebook", "--ip=0.0.0.0", "--port=8888", "--allow-root", "--notebook-dir=/notebooks"]
