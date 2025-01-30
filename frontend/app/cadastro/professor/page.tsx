"use client";

import { useRouter } from 'next/navigation';

export default function CadastroProfessor() {
  const router = useRouter();

  const handleLoginClick = () => {
    router.push('/login');
  };

  return (
    <div className="flex flex-col items-center justify-center min-h-screen bg-[#f9fafb] text-black p-6">
      <div className='flex flex-col items-center justify-center bg-white text-black py-12 px-20 rounded-xl shadow-md w-[840px]'>
        <h1 className="text-7xl font-bold mb-14">Cadastro</h1>
        <input
          className="p-4 mb-4 w-full rounded-lg text-black bg-[#fafafa] focus:border-primary focus:outline-none"
          type="text"
          placeholder="Login"
        />
        <input
          className="p-4 mb-4 w-full rounded-lg text-black bg-[#fafafa] focus:border-primary focus:outline-none"
          type="password"
          placeholder="Senha"
        />
        <input
          className="p-4 mb-4 w-full rounded-lg text-black bg-[#fafafa] focus:border-primary focus:outline-none"
          type="text"
          placeholder="Nome"
        />
        <input
          className="p-4 mb-4 w-full rounded-lg text-black bg-[#fafafa] focus:border-primary focus:outline-none"
          type="number"
          placeholder="Idade"
        />
        <input
          className="p-4 mb-4 w-full rounded-lg text-black bg-[#fafafa] focus:border-primary focus:outline-none"
          type="text"
          placeholder="CPF"
        />
        <input
          className="p-4 mb-4 w-full rounded-lg text-black bg-[#fafafa] focus:border-primary focus:outline-none"
          type="text"
          placeholder="Sexo"
        />
        <input
          className="p-4 mb-4 w-full rounded-lg text-black bg-[#fafafa] focus:border-primary focus:outline-none"
          type="date"
          placeholder="Data de Nascimento"
        />
        <input
          className="p-4 mb-4 w-full rounded-lg text-black bg-[#fafafa] focus:border-primary focus:outline-none"
          type="text"
          placeholder="RG"
        />
        <input
          className="p-4 mb-4 w-full rounded-lg text-black bg-[#fafafa] focus:border-primary focus:outline-none"
          type="email"
          placeholder="Email"
        />
        <input
          className="p-4 mb-4 w-full rounded-lg text-black bg-[#fafafa] focus:border-primary focus:outline-none"
          type="text"
          placeholder="Endereço"
        />
        <input
          className="p-4 mb-4 w-full rounded-lg text-black bg-[#fafafa] focus:border-primary focus:outline-none"
          type="number"
          placeholder="Salário"
        />
        <input
          className="p-4 mb-4 w-full rounded-lg text-black bg-[#fafafa] focus:border-primary focus:outline-none"
          type="text"
          placeholder="Tipo"
        />

        <div className='flex items-center justify-between w-full mt-8'>
          <button className="bg-primary text-white py-3 px-8 rounded-lg text-lg font-semibold shadow-md hover:bg-red-800">
            Cadastrar
          </button>
          <button 
            className="bg-primary text-white py-3 px-8 rounded-lg text-lg font-semibold shadow-md hover:bg-red-800"          
            onClick={handleLoginClick}
          >
            Já tenho conta
          </button>
        </div>
      </div>
    </div>
  );
}
