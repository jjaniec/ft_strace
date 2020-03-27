FROM		debian:stable

RUN			apt-get update -yqq && \
				apt-get install -y --no-install-recommends \
					gdb \
					valgrind \
					bash && \
			rm -rf /var/lib/apt/lists/*

ENTRYPOINT ["bash"]
