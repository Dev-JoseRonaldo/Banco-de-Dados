// app/login/page.tsx

"use client";

import { useRouter } from 'next/navigation';

export default function Login() {
  const router = useRouter();

  const handleCadastroClick = () => {
    router.push('/cadastro');
  };

  return (
    <div className="flex flex-col items-center justify-center min-h-screen bg-[#f9fafb] text-black p-6">
      <div className='flex flex-col items-center justify-center bg-white text-black p-20 rounded-xl shadow-md'>
        <h1 className="text-7xl font-bold mb-14">LkCIn</h1>
        <input
          className="p-4 mb-4 w-80 rounded-lg text-black bg-[#fafafa] focus:border-primary focus:outline-none"
          type="text"
          placeholder="Usuário"
        />
        <input
          className="p-4 mb-4 w-80 rounded-lg text-black bg-[#fafafa] focus:border-primary focus:outline-none"
          type="password"
          placeholder="Senha"
        />

        <div className='flex items-center justify-between w-80 mt-8'>
          <button className="bg-primary text-white py-3 px-8 rounded-lg text-lg font-semibold shadow-md hover:bg-red-800">
            Entrar
          </button>
          <button 
            className="bg-primary text-white py-3 px-8 rounded-lg text-lg font-semibold shadow-md hover:bg-red-800"          
            onClick={handleCadastroClick}
          >
            Cadastre-se
          </button>
        </div>
      </div>
    </div>
  );
}
