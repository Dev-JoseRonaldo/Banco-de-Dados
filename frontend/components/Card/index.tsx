'use client'

import { useRouter } from 'next/navigation';
import { JSX } from 'react';

type CardProps = {
  label: string;
  route: string;
  icon: JSX.Element;
};

export function Card({ label, route, icon }: CardProps) {
  const router = useRouter();
  return (
    <div
      className="flex flex-col items-center bg-primary text-white p-6 rounded-lg shadow-lg w-60 cursor-pointer hover:bg-red-800"
      onClick={() => router.push(route)}
    >
      <div className="text-5xl mb-4">{icon}</div>
      <p className="text-xl font-semibold">{label}</p>
    </div>
  );
}