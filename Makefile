#makefile

BIN_PATH=bin/
SRC_PATH=src/
COM_PATH=com/
HEAD_PATH=head/
TEST_PATH=test/
RES_NAME=my_ls
SRC_NAME=*.c
SUCC_STR="安装成功！"
REMV_STR="卸载成功！"
all : start

start :
	@gcc ${SRC_PATH}${SRC_NAME} -o ${BIN_PATH}${RES_NAME} -I ${HEAD_PATH} \
		&& echo -e "\e[0;31m" ${SUCC_STR} "\e[0;0m"
install :
	@cp ${BIN_PATH}${RES_NAME} ${TEST_PATH}${RES_NAME}                    \
        && cd ${TEST_PATH}
.PHONY : clean
clean :
	@rm -f ${BIN_PATH}${RES_NAME} ${TEST_PATH}${RES_NAME}                 \
		&& echo -e "\e[0;31m" ${REMV_STR} "\e[0;0m"
