/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:30:07 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/28 19:51:40 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : ptr_(NULL), size_(0) {}

template <typename T>
Array<T>::Array(const unsigned int size) : ptr_(NULL), size_(size) {
  if (size > 0) {
    ptr_ = new T[size]();
    // () is for value-initialize elements
  }
}

template <typename T>
Array<T>::Array(const Array<T>& other) : ptr_(NULL), size_(0) {
  *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& src) {
  if (this != &src) {
    T* tmp = NULL;
    if (src.size_ > 0) {
      tmp = new T[src.size_];
      for (unsigned int i = 0; i < src.size_; i++) {
        tmp[i] = src.ptr_[i];
      }
    }

    if (ptr_) delete[] ptr_;
    ptr_ = tmp;
    size_ = src.size_;
  }
  return *this;
}

template <typename T>
Array<T>::~Array() {
  if (ptr_) delete[] ptr_;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
  if (index >= size_) {
    throw IndexOutOfBoundsException();
  }
  return ptr_[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
  if (index >= size_) {
    throw IndexOutOfBoundsException();
  }
  return ptr_[index];
}

template <typename T>
unsigned int Array<T>::size() const {
  return size_;
}

template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw() {
  return "Index out of bounds";
}

