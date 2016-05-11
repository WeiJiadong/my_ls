#makefile

BIN_PATH=bin/
SRC_PATH=src/
HEAD_PATH=head/
COM_PATH=com/
RES_NAME=my_ls
SRC_NAME=*.c
SUCC_STR="创建成功！"
REMV_STR="删除成功！"
all : install

install :
	@gcc ${SRC_PATH}${SRC_NAME} -o ${BIN_PATH}${RES_NAME} -I ${HEAD_PATH} \
		&& echo -e "\e[0;31m" ${SUCC_STR} "\e[0;0m"
.PHONY : clean
clean :
	@rm -f ${BIN_PATH}${RES_NAME}                                          \
		&& echo -e "\e[0;31m" ${REMV_STR} "\e[0;0m"
