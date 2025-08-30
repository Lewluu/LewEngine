# Vulan Container running in ubuntu

FROM ubuntu:24.04

ENTRYPOINT ["/bin/bash"]

# Install dependencies
RUN apt-get update && apt-get install -y \
	vulkan-tools libvulkan-dev vulkan-validationlayers spirv-tools \
	libxxf86vm-dev libxi-dev libglm-dev libgl-dev dbus-x11 \ 
	libxcursor-dev libxinerama-dev libxrandr-dev libglfw3 libglfw3-dev \
	build-essential cmake ca-certificates gpg wget curl vim \
	fakeroot dpkg-dev devscripts debhelper-compat dh-python equivs \
	g++ python3 python3-venv git lshw

# Prepare python virtual environment
RUN python3 -m venv  /.venv

# Install pip
RUN curl -sSL https://bootstrap.pypa.io/get-pip.py -o get-pip.py && \
	./.venv/bin/python3 get-pip.py