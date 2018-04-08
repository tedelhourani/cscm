FROM gcc
RUN apt-get update
RUN apt-get install -y build-essential gdb
WORKDIR /usr/src/cscm
ENV PATH="/usr/src/cscm:${PATH}"
CMD ["bash"]
