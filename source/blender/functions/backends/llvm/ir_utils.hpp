#pragma once

#include "llvm_gen.hpp"
#include <llvm/IR/IRBuilder.h>

namespace FN {

	template<typename T>
	static llvm::ArrayRef<T> to_array_ref(SmallVector<T> &vector)
	{
		return llvm::ArrayRef<T>(vector.begin(), vector.end());
	}

	llvm::CallInst *call_pointer(
		llvm::IRBuilder<> &builder,
		const void *pointer,
		llvm::FunctionType *type,
		LLVMValues arguments);

	llvm::Value *lookup_tuple_address(
		llvm::IRBuilder<> &builder,
		llvm::Value *data_addr,
		llvm::Value *offsets_addr,
		uint index);

	llvm::Value *void_ptr_to_ir(llvm::IRBuilder<> &builder, void *ptr);
	llvm::Value *int_ptr_to_ir(llvm::IRBuilder<> &builder, int *ptr);
	llvm::Value *byte_ptr_to_ir(llvm::IRBuilder<> &builder, void *ptr);
	llvm::Value *ptr_to_ir(llvm::IRBuilder<> &builder, void *ptr, llvm::Type *type);

	LLVMTypes types_of_values(const LLVMValues &values);

	llvm::Value *alloca_bytes(llvm::IRBuilder<> &builder, uint size);
 } /* namespace FN */