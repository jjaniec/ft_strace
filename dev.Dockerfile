FROM		debian:stable

RUN			apt-get update -yqq && \
				apt-get install -y --no-install-recommends \
					gdb \
					valgrind \
					bash \
					make \
					binutils \
					gcc \
					build-essential \
					psmisc \
					strace \
					gcc-multilib \
					&& \
			rm -rf /var/lib/apt/lists/*

ENTRYPOINT ["bash"]
